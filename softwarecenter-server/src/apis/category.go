package apis

import (
	"gopkg.in/gin-gonic/gin.v1"
	"log"
	"models"
    db "databases"
	"net/http"
	"strconv"
)

func AddCategoryApi(c *gin.Context) {

	var p models.ScCategory
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

func GetCategoryAllApi(c *gin.Context) {

	ra, err := models.GetScCategories(db.SqlDB)

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

	p, err := models.ScCategoryByID(db.SqlDB, uint(id))

	if err != nil {
		log.Println(err)
		return
	}

	c.JSON(http.StatusOK, gin.H{
		"Category": p,
	})
}

func ModCategoryApi(c *gin.Context) {
	cid := c.Param("id")
	id, err := strconv.Atoi(cid)
	if err != nil {
		log.Println(err)
		id = 0
	}

	var p models.ScCategory
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

	c.JSON(http.StatusOK, gin.H{
		"ID":   p.ID,
	})
}

