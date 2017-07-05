// Package models contains the types for schema 'emind_software_center'.
package models

// GENERATED BY XO. DO NOT EDIT.

import "errors"

// ScRecommend represents a row from 'emind_software_center.sc_recommend'.
type ScRecommend struct {
	ID       uint `json:"ID" form:"ID"`             // ID
	Priority int8 `json:"priority" form:"priority"` // priority

	// xo fields
	_exists, _deleted bool
}

// Exists determines if the ScRecommend exists in the database.
func (sr *ScRecommend) Exists() bool {
	return sr._exists
}

// Deleted provides information if the ScRecommend has been deleted from the database.
func (sr *ScRecommend) Deleted() bool {
	return sr._deleted
}

// Insert inserts the ScRecommend to the database.
func (sr *ScRecommend) Insert(db XODB) error {
	var err error

	// if already exist, bail
	if sr._exists {
		return errors.New("insert failed: already exists")
	}

	// sql insert query, primary key must be provided
	const sqlstr = `INSERT INTO emind_software_center.sc_recommend (` +
		`ID, priority` +
		`) VALUES (` +
		`?, ?` +
		`)`

	// run query
	XOLog(sqlstr, sr.ID, sr.Priority)
	_, err = db.Exec(sqlstr, sr.ID, sr.Priority)
	if err != nil {
		return err
	}

	// set existence
	sr._exists = true

	return nil
}

// Update updates the ScRecommend in the database.
func (sr *ScRecommend) Update(db XODB) error {
	var err error

	// if doesn't exist, bail
	if !sr._exists {
		return errors.New("update failed: does not exist")
	}

	// if deleted, bail
	if sr._deleted {
		return errors.New("update failed: marked for deletion")
	}

	// sql query
	const sqlstr = `UPDATE emind_software_center.sc_recommend SET ` +
		`priority = ?` +
		` WHERE ID = ?`

	// run query
	XOLog(sqlstr, sr.Priority, sr.ID)
	_, err = db.Exec(sqlstr, sr.Priority, sr.ID)
	return err
}

// Save saves the ScRecommend to the database.
func (sr *ScRecommend) Save(db XODB) error {
	if sr.Exists() {
		return sr.Update(db)
	}

	return sr.Insert(db)
}

// Delete deletes the ScRecommend from the database.
func (sr *ScRecommend) Delete(db XODB) error {
	var err error

	// if doesn't exist, bail
	if !sr._exists {
		return nil
	}

	// if deleted, bail
	if sr._deleted {
		return nil
	}

	// sql query
	const sqlstr = `DELETE FROM emind_software_center.sc_recommend WHERE ID = ?`

	// run query
	XOLog(sqlstr, sr.ID)
	_, err = db.Exec(sqlstr, sr.ID)
	if err != nil {
		return err
	}

	// set deleted
	sr._deleted = true

	return nil
}

// ScProduct returns the ScProduct associated with the ScRecommend's ID (ID).
//
// Generated from foreign key 'sc_recommend_ibfk_1'.
func (sr *ScRecommend) ScProduct(db XODB) (*ScProduct, error) {
	return ScProductByID(db, sr.ID)
}

// ScRecommendByID retrieves a row from 'emind_software_center.sc_recommend' as a ScRecommend.
//
// Generated from index 'sc_recommend_ID_pkey'.
func ScRecommendByID(db XODB, id uint) (*ScRecommend, error) {
	var err error

	// sql query
	const sqlstr = `SELECT ` +
		`ID, priority ` +
		`FROM emind_software_center.sc_recommend ` +
		`WHERE ID = ?`

	// run query
	XOLog(sqlstr, id)
	sr := ScRecommend{
		_exists: true,
	}

	err = db.QueryRow(sqlstr, id).Scan(&sr.ID, &sr.Priority)
	if err != nil {
		return nil, err
	}

	return &sr, nil
}