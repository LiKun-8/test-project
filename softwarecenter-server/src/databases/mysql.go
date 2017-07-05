package databases

import (
	"database/sql"
	"log"

	_ "github.com/go-sql-driver/mysql"
)

var SqlDB *sql.DB

func init() {
	var err error

	if SqlDB, err = sql.Open("mysql",
		//"emindsoftwarecenter:p#.!$!%(26i@tcp(127.0.0.1:3306)/EmindSoftwareCenter?charset=utf8&parseTime=True"); err != nil {
		"emindsoftwarecenter:1@tcp(127.0.0.1:3306)/emind_software_center?charset=utf8&parseTime=True"); err != nil {
		log.Fatal(err.Error())
	}

	SqlDB.SetMaxIdleConns(20)
	SqlDB.SetMaxOpenConns(20)

	if err = SqlDB.Ping(); err != nil {
		log.Fatal(err.Error())
	}

}
