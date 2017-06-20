package databases

import (
	_ "github.com/go-sql-driver/mysql"
	"github.com/jmoiron/sqlx"
	"log"
)

var SqlDB *sqlx.DB

func init() {
	var err error

	SqlDB, err = sqlx.Open("mysql", "emindsoftwarecenter:p#.!$!%(26i@tcp(127.0.0.1:3306)/EmindSoftwareCenter?charset=utf8&parseTime=True")
	if err != nil {
		log.Fatal(err.Error())
	}

	SqlDB.SetMaxIdleConns(20)
	SqlDB.SetMaxOpenConns(20)

	err = SqlDB.Ping()
	if err != nil {
		log.Fatal(err.Error())
	}

}
