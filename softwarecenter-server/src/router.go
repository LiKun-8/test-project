package main

import (
	. "apis"
	"gopkg.in/gin-gonic/gin.v1"
)

func initRouter() *gin.Engine {
	router := gin.Default()

	router.GET("/", IndexApi)

	router.POST("/release", AddReleaseApi)
	router.GET("/release/:id", GetReleaseApi)

	router.POST("/product", AddProductApi)
	router.PUT("/product/:id", ModProductApi)
	router.GET("/product/:id", GetProductApi)
	router.GET("/products", GetProductAllApi)
	router.GET("/product_from_name", GetProductFromNameApi)

	router.POST("/category", AddCategoryApi)
	router.PUT("/category/:id", ModCategoryApi)
	router.GET("/category/:id", GetCategoryApi)
	router.GET("/categories", GetCategoryAllApi)

	return router
}
