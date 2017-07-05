// Package models contains the types for schema 'emind_software_center'.
package models

// GENERATED BY XO. DO NOT EDIT.

import "errors"

// ScBanner represents a row from 'emind_software_center.sc_banners'.
type ScBanner struct {
	ID       uint `json:"ID" form:"ID"`             // ID
	Priority int8 `json:"priority" form:"priority"` // priority

	// xo fields
	_exists, _deleted bool
}

// Exists determines if the ScBanner exists in the database.
func (sb *ScBanner) Exists() bool {
	return sb._exists
}

// Deleted provides information if the ScBanner has been deleted from the database.
func (sb *ScBanner) Deleted() bool {
	return sb._deleted
}

// Insert inserts the ScBanner to the database.
func (sb *ScBanner) Insert(db XODB) error {
	var err error

	// if already exist, bail
	if sb._exists {
		return errors.New("insert failed: already exists")
	}

	// sql insert query, primary key must be provided
	const sqlstr = `INSERT INTO emind_software_center.sc_banners (` +
		`ID, priority` +
		`) VALUES (` +
		`?, ?` +
		`)`

	// run query
	XOLog(sqlstr, sb.ID, sb.Priority)
	_, err = db.Exec(sqlstr, sb.ID, sb.Priority)
	if err != nil {
		return err
	}

	// set existence
	sb._exists = true

	return nil
}

// Update updates the ScBanner in the database.
func (sb *ScBanner) Update(db XODB) error {
	var err error

	// if doesn't exist, bail
	if !sb._exists {
		return errors.New("update failed: does not exist")
	}

	// if deleted, bail
	if sb._deleted {
		return errors.New("update failed: marked for deletion")
	}

	// sql query
	const sqlstr = `UPDATE emind_software_center.sc_banners SET ` +
		`priority = ?` +
		` WHERE ID = ?`

	// run query
	XOLog(sqlstr, sb.Priority, sb.ID)
	_, err = db.Exec(sqlstr, sb.Priority, sb.ID)
	return err
}

// Save saves the ScBanner to the database.
func (sb *ScBanner) Save(db XODB) error {
	if sb.Exists() {
		return sb.Update(db)
	}

	return sb.Insert(db)
}

// Delete deletes the ScBanner from the database.
func (sb *ScBanner) Delete(db XODB) error {
	var err error

	// if doesn't exist, bail
	if !sb._exists {
		return nil
	}

	// if deleted, bail
	if sb._deleted {
		return nil
	}

	// sql query
	const sqlstr = `DELETE FROM emind_software_center.sc_banners WHERE ID = ?`

	// run query
	XOLog(sqlstr, sb.ID)
	_, err = db.Exec(sqlstr, sb.ID)
	if err != nil {
		return err
	}

	// set deleted
	sb._deleted = true

	return nil
}

// ScProduct returns the ScProduct associated with the ScBanner's ID (ID).
//
// Generated from foreign key 'sc_banners_ibfk_1'.
func (sb *ScBanner) ScProduct(db XODB) (*ScProduct, error) {
	return ScProductByID(db, sb.ID)
}

// ScBannerByID retrieves a row from 'emind_software_center.sc_banners' as a ScBanner.
//
// Generated from index 'sc_banners_ID_pkey'.
func ScBannerByID(db XODB, id uint) (*ScBanner, error) {
	var err error

	// sql query
	const sqlstr = `SELECT ` +
		`ID, priority ` +
		`FROM emind_software_center.sc_banners ` +
		`WHERE ID = ?`

	// run query
	XOLog(sqlstr, id)
	sb := ScBanner{
		_exists: true,
	}

	err = db.QueryRow(sqlstr, id).Scan(&sb.ID, &sb.Priority)
	if err != nil {
		return nil, err
	}

	return &sb, nil
}