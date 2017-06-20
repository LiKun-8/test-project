package apis

import (
	"gopkg.in/gin-gonic/gin.v1"
	"log"
	. "models"
	"net/http"
	"strconv"
)

func AddCategoryApi(c *gin.Context) {

	var p Category
	err := c.Bind(&p)
	if err != nil {
		log.Println(err)
		return
	}

	ra, err := p.AddCategory()
	if err != nil {
		log.Println(err)
		return
	}

	c.JSON(http.StatusOK, gin.H{
		"ID": ra,
	})
}

func GetCategoryAllApi(c *gin.Context) {

	var p Category
	ra, err := p.GetCategoryAll()

	if err != nil {
		log.Println(err)
		return
	}

	c.JSON(http.StatusOK, gin.H{
		"Categories": ra,
	})
}

func GetCategoryApi(c *gin.Context) {
	cid := c.Param("id")
	id, err := strconv.Atoi(cid)
	if err != nil {
		log.Println(err)
		id = 0
	}

	var p Category
	p.CategoryID = id

	category, err := p.GetCategory()

	if err != nil {
		log.Println(err)
		return
	}

	c.JSON(http.StatusOK, gin.H{
		"Category": category,
	})
}

func ModCategoryApi(c *gin.Context) {
	cid := c.Param("id")
	id, err := strconv.Atoi(cid)
	if err != nil {
		log.Println(err)
		id = 0
	}

	var p Category
	err = c.Bind(&p)
	if err != nil {
		log.Println(err)
		return
	}

	p.CategoryID = id

	ra, err := p.ModCategory()

	if err != nil {
		log.Println(err)
		return
	}

	c.JSON(http.StatusOK, gin.H{
		"ID":   p.CategoryID,
		"Rows": ra,
	})
}
