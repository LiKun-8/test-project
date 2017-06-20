package main

import (
	db "databases"
)

func main() {
	defer db.SqlDB.Close()
	router := initRouter()
	router.Run(":8888")
}
