package apis

import (
	"gopkg.in/gin-gonic/gin.v1"
	"log"
	. "models"
	"net/http"
	"strconv"
)

func IndexApi(c *gin.Context) {
	c.String(http.StatusOK, "It works")
}

func AddProductApi(c *gin.Context) {

	var p Product
	err := c.Bind(&p)
	if err != nil {
		log.Println(err)
		return
	}

	ra, err := p.AddProduct()
	if err != nil {
		log.Println(err)
		return
	}

	//msg := log.Sprintf("insert successful %d", ra)
	c.JSON(http.StatusOK, gin.H{
		"ID": ra,
	})
}

func GetProductAllApi(c *gin.Context) {

	var p Product
	ra, err := p.GetProductAll()

	if err != nil {
		log.Println(err)
		return
	}

	c.JSON(http.StatusOK, gin.H{
		"products": ra,
	})
}

func GetProductFromNameApi(c *gin.Context) {

	var p Product
	err := c.Bind(&p)
	if err != nil {
		log.Println(err)
		return
	}

	product, err := p.GetProductFromName()

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

	var p Product
	p.ProductID = id

	product, err := p.GetProduct()

	if err != nil {
		log.Println(err)
		return
	}

	c.JSON(http.StatusOK, gin.H{
		"product": product,
	})
}

func ModProductApi(c *gin.Context) {
	cid := c.Param("id")
	id, err := strconv.Atoi(cid)
	if err != nil {
		log.Println(err)
		id = 0
	}

	var p Product
	err = c.Bind(&p)
	if err != nil {
		log.Println(err)
		return
	}

	p.ProductID = id
	ra, err := p.ModProduct()

	if err != nil {
		log.Println(err)
		return
	}

	//msg := log.Sprintf("Update product %d successful %d", p.ProductID, ra)
	c.JSON(http.StatusOK, gin.H{
		"ID":   p.ProductID,
		"Rows": ra,
	})
}
