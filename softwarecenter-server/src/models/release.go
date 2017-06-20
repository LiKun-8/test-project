package modules

import (
	db "databases"
	"time"
)

type Release struct {
	ReleaseID    int       `json:"release_id" form:"release_id" db:"ReleaseID"`
	ProductID    int       `json:"product_id" form:"product_id" db:"ProductID"`
	Version      string    `json:"version" form:"version" db:"Version"`
	IconUrl      string    `json:"icon_url" form:"icon_url" db:"IconUrl"`
	DownloadUrl  string    `json:"download_url" form:"download_url" db:"DownloadUrl"`
	Changelog    string    `json:"changelog" form:"changelog" db:"Changelog"`
	PackageSize  int       `json:"package_size" form:"package_size" db:"PackageSize"`
	PackageType  int       `json:"package_type" form:"package_type" db:"PackageType"`
	ReleaseGrade int       `json:"release_grade" form:"release_grade" db:"ReleaseGrade"`
	GradeCount   int       `json:"grade_count" form:"grade_count" db:"GradeCount"`
	ReleaseDate  time.Time `json:"release_date" form:"release_date" db:"ReleaseDate"`
}

func (p *Release) AddRelease() (id int64, err error) {

	stmt, err := db.SqlDB.Prepare("INSERT INTO sc_release(ProductID, Version, IconUrl, DownloadUrl, ChangeLog, PackageSize, PackageType, ReleaseGrade, GradeCount, ReleaseDate) VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?)")
	defer stmt.Close()

	if err != nil {
		return
	}

	rs, err := stmt.Exec(p.ProductID, p.Version, p.IconUrl, p.DownloadUrl, p.Changelog, p.PackageSize, p.PackageType, p.ReleaseGrade, p.GradeCount, p.ReleaseDate)
	if err != nil {
		return
	}

	id, err = rs.LastInsertId()
	if err != nil {
		return
	}

	stmt_product, err := db.SqlDB.Prepare("UPDATE sc_product SET ReleaseID=?, IconUrl=? WHERE ProductID=?")
	defer stmt_product.Close()
	if err != nil {
		return
	}

	rs, err = stmt_product.Exec(id, p.IconUrl, p.ProductID)
	if err != nil {
		return
	}

	_, err = rs.RowsAffected()

	return
}

func (p *Release) GetRelease() (release Release, err error) {
	err = db.SqlDB.Get(&release, "SELECT * FROM sc_release WHERE ReleaseID=?", p.ReleaseID)
	return
}
