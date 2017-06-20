package modules

import (
	db "databases"
)

type Category struct {
	CategoryID   int    `json:"category_id" form:"category_id" db:"CategoryID"`
	CategoryName string `json:"category_name" form:"category_name" db:"CategoryName"`
}

func (p *Category) AddCategory() (id int64, err error) {

	stmt, err := db.SqlDB.Prepare("INSERT INTO sc_category(CategoryName) VALUES (?)")
	defer stmt.Close()

	if err != nil {
		return
	}

	rs, err := stmt.Exec(p.CategoryName)
	if err != nil {
		return
	}

	id, err = rs.LastInsertId()

	return
}

func (p *Category) GetCategoryAll() (categories []Category, err error) {
	categories = make([]Category, 0)

	err = db.SqlDB.Select(&categories, "SELECT CategoryID, CategoryName FROM sc_category")

	return
}

func (p *Category) GetCategory() (category Category, err error) {
	err = db.SqlDB.Get(&category, "SELECT CategoryID, CategoryName FROM sc_category WHERE CategoryID=?", p.CategoryID)
	return
}

func (p *Category) ModCategory() (ra int64, err error) {
	stmt, err := db.SqlDB.Prepare("UPDATE sc_category SET CategoryName=? WHERE CategoryID=?")
	defer stmt.Close()
	if err != nil {
		return
	}

	rs, err := stmt.Exec(p.CategoryName, p.CategoryID)
	if err != nil {
		return
	}
	ra, err = rs.RowsAffected()
	return
}
