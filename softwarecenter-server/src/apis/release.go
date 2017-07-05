package apis

import (
	db "databases"
	"log"
	"models"
	"net/http"
	"strconv"

	"gopkg.in/gin-gonic/gin.v1"
)

func AddReleaseApi(c *gin.Context) {

	var p models.ScRelease
	if err := c.Bind(&p); err != nil {
		log.Println(err)
		return
	}

	err := p.AddRelaseAndUpdateProduct(db.SqlDB)
	if err != nil {
		log.Println(err)
		return
	}

	c.JSON(http.StatusOK, gin.H{
		"ID": p.ID,
	})
}

func GetReleaseApi(c *gin.Context) {
	cid := c.Param("id")
	id, err := strconv.Atoi(cid)
	if err != nil {
		log.Println(err)
		id = 0
	}

	p, err := models.ScReleaseByID(db.SqlDB, uint(id))

	if err != nil {
		log.Println(err)
		return
	}

	c.JSON(http.StatusOK, gin.H{
		"release": p,
	})
}
