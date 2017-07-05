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

func easyjsonF0648bdeDecodeModels(in *jlexer.Lexer, out *ScScreenImage) {
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
		case "release_ID":
			out.ReleaseID = uint(in.Uint())
		case "image_url":
			out.ImageURL = string(in.String())
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
func easyjsonF0648bdeEncodeModels(out *jwriter.Writer, in ScScreenImage) {
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
	out.RawString("\"release_ID\":")
	out.Uint(uint(in.ReleaseID))
	if !first {
		out.RawByte(',')
	}
	first = false
	out.RawString("\"image_url\":")
	out.String(string(in.ImageURL))
	out.RawByte('}')
}

// MarshalJSON supports json.Marshaler interface
func (v ScScreenImage) MarshalJSON() ([]byte, error) {
	w := jwriter.Writer{}
	easyjsonF0648bdeEncodeModels(&w, v)
	return w.Buffer.BuildBytes(), w.Error
}

// MarshalEasyJSON supports easyjson.Marshaler interface
func (v ScScreenImage) MarshalEasyJSON(w *jwriter.Writer) {
	easyjsonF0648bdeEncodeModels(w, v)
}

// UnmarshalJSON supports json.Unmarshaler interface
func (v *ScScreenImage) UnmarshalJSON(data []byte) error {
	r := jlexer.Lexer{Data: data}
	easyjsonF0648bdeDecodeModels(&r, v)
	return r.Error()
}

// UnmarshalEasyJSON supports easyjson.Unmarshaler interface
func (v *ScScreenImage) UnmarshalEasyJSON(l *jlexer.Lexer) {
	easyjsonF0648bdeDecodeModels(l, v)
}