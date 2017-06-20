package modules

import (
	db "databases"
)

type Product struct {
	ProductID          int    `json:"product_id" form:"product_id" db:"ProductID"`
	ReleaseID          int    `json:"release_id" form:"release_id" db:"ReleaseID"`
	CategoryID         int    `json:"category_id" form:"category_id" db:"CategoryID"`
	ProductName        string `json:"product_name" form:"product_name" db:"ProductName"`
	VendorName         string `json:"vendor_name" form:"vendor_name" db:"VendorName"`
	IconUrl            string `json:"icon_url" form:"icon_url" db:"IconUrl"`
	Url                string `json:"url" form:"url" db:"Url"`
	ProductDescription string `json:"product_description" form:"product_description" db:"ProductDescription"`
	ProductGrade       int    `json:"product_grade" form:"product_grade" db:"ProductGrade"`
	GradeCount         int    `json:"grade_count" form:"grade_count" db:"GradeCount"`
}

func (p *Product) AddProduct() (id int64, err error) {

	stmt, err := db.SqlDB.Prepare("INSERT INTO sc_product(ProductName, VendorName, CategoryID, Url, ProductDescription) VALUES (?, ?, ?, ?, ?)")
	defer stmt.Close()

	if err != nil {
		return
	}

	rs, err := stmt.Exec(p.ProductName, p.VendorName, p.CategoryID, p.Url, p.ProductDescription)
	if err != nil {
		return
	}

	id, err = rs.LastInsertId()

	return
}

func (p *Product) GetProductAll() (products []Product, err error) {
	products = make([]Product, 0)

	err = db.SqlDB.Select(&products, "SELECT ProductID, ReleaseID, CategoryID, IconUrl, ProductName, VendorName, Url, ProductDescription, ProductGrade, GradeCount FROM sc_product")
	return
}

func (p *Product) GetProductFromName() (product Product, err error) {
	err = db.SqlDB.Get(&product, "SELECT ProductID, ReleaseID, CategoryID, IconUrl, ProductName, VendorName, Url, ProductDescription, ProductGrade, GradeCount FROM sc_product WHERE ProductName=?", p.ProductName)
	return
}

func (p *Product) GetProduct() (product Product, err error) {
	err = db.SqlDB.Get(&product, "SELECT ProductID, ReleaseID, CategoryID, IconUrl, ProductName, VendorName, Url, ProductDescription, ProductGrade, GradeCount FROM sc_product WHERE ProductID=?", p.ProductID)
	return
}

func (p *Product) ModProduct() (ra int64, err error) {
	stmt, err := db.SqlDB.Prepare("UPDATE sc_product SET CategoryID=?, ProductName=?, VendorName=?, Url=?, ProductDescription=? WHERE ProductID=?")
	defer stmt.Close()
	if err != nil {
		return
	}
	rs, err := stmt.Exec(p.CategoryID, p.ProductName, p.VendorName, p.Url, p.ProductDescription, p.ProductID)
	if err != nil {
		return
	}
	ra, err = rs.RowsAffected()
	return
}
