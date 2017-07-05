// Code generated by easyjson for marshaling/unmarshaling. DO NOT EDIT.

package models

import (
	json "encoding/json"
	mysql "github.com/go-sql-driver/mysql"
	easyjson "github.com/mailru/easyjson"
	jlexer "github.com/mailru/easyjson/jlexer"
	jwriter "github.com/mailru/easyjson/jwriter"
)

// suppress unused package warning
var (
	_ *json.RawMessage
	_ *jlexer.Lexer
	_ *jwriter.Writer
	_ easyjson.Marshaler
)

func easyjson5fc6d99fDecodeModels(in *jlexer.Lexer, out *ScRelease) {
	isTopLevel := in.IsStart()
	if in.IsNull() {
		if isTopLevel {
			in.Consumed()
		}
		in.Skip()
		return
	}
	in.Delim('{')
	for !in.IsDelim('}') {
		key := in.UnsafeString()
		in.WantColon()
		if in.IsNull() {
			in.Skip()
			in.WantComma()
			continue
		}
		switch key {
		case "ID":
			out.ID = uint(in.Uint())
		case "product_ID":
			out.ProductID = uint(in.Uint())
		case "version":
			out.Version = string(in.String())
		case "icon_url":
			out.IconURL = string(in.String())
		case "download_url":
			out.DownloadURL = string(in.String())
		case "changelog":
			out.Changelog = string(in.String())
		case "package_size":
			out.PackageSize = uint(in.Uint())
		case "package_type":
			out.PackageType = int8(in.Int8())
		case "release_grade":
			out.ReleaseGrade = uint(in.Uint())
		case "grade_count":
			out.GradeCount = uint(in.Uint())
		case "release_date":
			easyjson5fc6d99fDecodeGithubComGoSqlDriverMysql(in, &out.ReleaseDate)
		default:
			in.SkipRecursive()
		}
		in.WantComma()
	}
	in.Delim('}')
	if isTopLevel {
		in.Consumed()
	}
}
func easyjson5fc6d99fEncodeModels(out *jwriter.Writer, in ScRelease) {
	out.RawByte('{')
	first := true
	_ = first
	if !first {
		out.RawByte(',')
	}
	first = false
	out.RawString("\"ID\":")
	out.Uint(uint(in.ID))
	if !first {
		out.RawByte(',')
	}
	first = false
	out.RawString("\"product_ID\":")
	out.Uint(uint(in.ProductID))
	if !first {
		out.RawByte(',')
	}
	first = false
	out.RawString("\"version\":")
	out.String(string(in.Version))
	if !first {
		out.RawByte(',')
	}
	first = false
	out.RawString("\"icon_url\":")
	out.String(string(in.IconURL))
	if !first {
		out.RawByte(',')
	}
	first = false
	out.RawString("\"download_url\":")
	out.String(string(in.DownloadURL))
	if !first {
		out.RawByte(',')
	}
	first = false
	out.RawString("\"changelog\":")
	out.String(string(in.Changelog))
	if !first {
		out.RawByte(',')
	}
	first = false
	out.RawString("\"package_size\":")
	out.Uint(uint(in.PackageSize))
	if !first {
		out.RawByte(',')
	}
	first = false
	out.RawString("\"package_type\":")
	out.Int8(int8(in.PackageType))
	if !first {
		out.RawByte(',')
	}
	first = false
	out.RawString("\"release_grade\":")
	out.Uint(uint(in.ReleaseGrade))
	if !first {
		out.RawByte(',')
	}
	first = false
	out.RawString("\"grade_count\":")
	out.Uint(uint(in.GradeCount))
	if !first {
		out.RawByte(',')
	}
	first = false
	out.RawString("\"release_date\":")
	easyjson5fc6d99fEncodeGithubComGoSqlDriverMysql(out, in.ReleaseDate)
	out.RawByte('}')
}

// MarshalJSON supports json.Marshaler interface
func (v ScRelease) MarshalJSON() ([]byte, error) {
	w := jwriter.Writer{}
	easyjson5fc6d99fEncodeModels(&w, v)
	return w.Buffer.BuildBytes(), w.Error
}

// MarshalEasyJSON supports easyjson.Marshaler interface
func (v ScRelease) MarshalEasyJSON(w *jwriter.Writer) {
	easyjson5fc6d99fEncodeModels(w, v)
}

// UnmarshalJSON supports json.Unmarshaler interface
func (v *ScRelease) UnmarshalJSON(data []byte) error {
	r := jlexer.Lexer{Data: data}
	easyjson5fc6d99fDecodeModels(&r, v)
	return r.Error()
}

// UnmarshalEasyJSON supports easyjson.Unmarshaler interface
func (v *ScRelease) UnmarshalEasyJSON(l *jlexer.Lexer) {
	easyjson5fc6d99fDecodeModels(l, v)
}
func easyjson5fc6d99fDecodeGithubComGoSqlDriverMysql(in *jlexer.Lexer, out *mysql.NullTime) {
	isTopLevel := in.IsStart()
	if in.IsNull() {
		if isTopLevel {
			in.Consumed()
		}
		in.Skip()
		return
	}
	in.Delim('{')
	for !in.IsDelim('}') {
		key := in.UnsafeString()
		in.WantColon()
		if in.IsNull() {
			in.Skip()
			in.WantComma()
			continue
		}
		switch key {
		case "Time":
			if data := in.Raw(); in.Ok() {
				in.AddError((out.Time).UnmarshalJSON(data))
			}
		case "Valid":
			out.Valid = bool(in.Bool())
		default:
			in.SkipRecursive()
		}
		in.WantComma()
	}
	in.Delim('}')
	if isTopLevel {
		in.Consumed()
	}
}
func easyjson5fc6d99fEncodeGithubComGoSqlDriverMysql(out *jwriter.Writer, in mysql.NullTime) {
	out.RawByte('{')
	first := true
	_ = first
	if !first {
		out.RawByte(',')
	}
	first = false
	out.RawString("\"Time\":")
	out.Raw((in.Time).MarshalJSON())
	if !first {
		out.RawByte(',')
	}
	first = false
	out.RawString("\"Valid\":")
	out.Bool(bool(in.Valid))
	out.RawByte('}')
}
