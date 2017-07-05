// Code generated by easyjson for marshaling/unmarshaling. DO NOT EDIT.

package models

import (
	json "encoding/json"
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

func easyjson146a2558DecodeModels(in *jlexer.Lexer, out *ScProduct) {
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
		case "category_ID":
			out.CategoryID = uint(in.Uint())
		case "release_ID":
			out.ReleaseID = uint(in.Uint())
		case "product_name":
			out.ProductName = string(in.String())
		case "vendor_name":
			out.VendorName = string(in.String())
		case "icon_url":
			out.IconURL = string(in.String())
		case "url":
			out.URL = string(in.String())
		case "product_description":
			out.ProductDescription = string(in.String())
		case "product_grade":
			out.ProductGrade = uint(in.Uint())
		case "grade_count":
			out.GradeCount = uint(in.Uint())
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
func easyjson146a2558EncodeModels(out *jwriter.Writer, in ScProduct) {
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
	out.RawString("\"category_ID\":")
	out.Uint(uint(in.CategoryID))
	if !first {
		out.RawByte(',')
	}
	first = false
	out.RawString("\"release_ID\":")
	out.Uint(uint(in.ReleaseID))
	if !first {
		out.RawByte(',')
	}
	first = false
	out.RawString("\"product_name\":")
	out.String(string(in.ProductName))
	if !first {
		out.RawByte(',')
	}
	first = false
	out.RawString("\"vendor_name\":")
	out.String(string(in.VendorName))
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
	out.RawString("\"url\":")
	out.String(string(in.URL))
	if !first {
		out.RawByte(',')
	}
	first = false
	out.RawString("\"product_description\":")
	out.String(string(in.ProductDescription))
	if !first {
		out.RawByte(',')
	}
	first = false
	out.RawString("\"product_grade\":")
	out.Uint(uint(in.ProductGrade))
	if !first {
		out.RawByte(',')
	}
	first = false
	out.RawString("\"grade_count\":")
	out.Uint(uint(in.GradeCount))
	out.RawByte('}')
}

// MarshalJSON supports json.Marshaler interface
func (v ScProduct) MarshalJSON() ([]byte, error) {
	w := jwriter.Writer{}
	easyjson146a2558EncodeModels(&w, v)
	return w.Buffer.BuildBytes(), w.Error
}

// MarshalEasyJSON supports easyjson.Marshaler interface
func (v ScProduct) MarshalEasyJSON(w *jwriter.Writer) {
	easyjson146a2558EncodeModels(w, v)
}

// UnmarshalJSON supports json.Unmarshaler interface
func (v *ScProduct) UnmarshalJSON(data []byte) error {
	r := jlexer.Lexer{Data: data}
	easyjson146a2558DecodeModels(&r, v)
	return r.Error()
}

// UnmarshalEasyJSON supports easyjson.Unmarshaler interface
func (v *ScProduct) UnmarshalEasyJSON(l *jlexer.Lexer) {
	easyjson146a2558DecodeModels(l, v)
}