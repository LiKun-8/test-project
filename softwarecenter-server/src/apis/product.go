package apis

import (
	db "databases"
	"log"
	"models"
	"net/http"
	"strconv"

	"gopkg.in/gin-gonic/gin.v1"
)

func IndexApi(c *gin.Context) {
	c.String(http.StatusOK, "It works")
}

func AddProductApi(c *gin.Context) {

	var p models.ScProduct
	err := c.Bind(&p)
	if err != nil {
		log.Println(err)
		return
	}

	err = p.Save(db.SqlDB)
	if err != nil {
		log.Println(err)
		return
	}

	c.JSON(http.StatusOK, gin.H{
		"ID": p.ID,
	})
}

func GetProductAllApi(c *gin.Context) {

	ra, err := models.GetScProducts(db.SqlDB)
	if err != nil {
		log.Println(err)
		return
	}

	c.JSON(http.StatusOK, gin.H{
		"products": ra,
	})
}

func GetProductFromNameApi(c *gin.Context) {

	name := c.Query("product_name")

	product, err := models.ScProductsByProductName(db.SqlDB, name)

	if err != nil {
		log.Println(err)
		return
	}

	c.JSON(http.StatusOK, gin.H{
		"product": product,
	})
}

func GetProductApi(c *gin.Context) {
	cid := c.Param("id")
	id, err := strconv.Atoi(cid)
	if err != nil {
		log.Println(err)
		id = 0
	}

	p, err := models.ScProductByID(db.SqlDB, uint(id))

	if err != nil {
		log.Println(err)
		return
	}

	c.JSON(http.StatusOK, gin.H{
		"product": p,
	})
}

func ModProductApi(c *gin.Context) {
	cid := c.Param("id")
	id, err := strconv.Atoi(cid)
	if err != nil {
		log.Println(err)
		id = 0
	}

	var p models.ScProduct
	err = c.Bind(&p)
	if err != nil {
		log.Println(err)
		return
	}

	p.ID = uint(id)
	err = p.Save(db.SqlDB)

	if err != nil {
		log.Println(err)
		return
	}

	//msg := log.Sprintf("Update product %d successful %d", p.ProductID, ra)
	c.JSON(http.StatusOK, gin.H{
		"ID":   p.ID,
	})
}

func GetProductAndReleaseAllApi(c *gin.Context) {

	ra, err := models.GetScProductAndReleases(db.SqlDB)
	if err != nil {
		log.Println(err)
		return
	}

	c.JSON(http.StatusOK, gin.H{
		"products_release": ra,
	})
}

