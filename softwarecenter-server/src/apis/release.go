package apis

import (
	"gopkg.in/gin-gonic/gin.v1"
	"log"
	. "models"
	"net/http"
	"strconv"
)

func AddReleaseApi(c *gin.Context) {

	var p Release
	err := c.Bind(&p)
	if err != nil {
		log.Println(err)
		return
	}

	ra, err := p.AddRelease()
	if err != nil {
		log.Println(err)
		return
	}

	c.JSON(http.StatusOK, gin.H{
		"ID": ra,
	})
}

func GetReleaseApi(c *gin.Context) {
	cid := c.Param("id")
	id, err := strconv.Atoi(cid)
	if err != nil {
		log.Println(err)
		id = 0
	}

	var p Release
	p.ReleaseID = id

	release, err := p.GetRelease()

	if err != nil {
		log.Println(err)
		return
	}

	c.JSON(http.StatusOK, gin.H{
		"release": release,
	})
}
