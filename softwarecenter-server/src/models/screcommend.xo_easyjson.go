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

func easyjsonAd788e3dDecodeModels(in *jlexer.Lexer, out *ScRecommend) {
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
		case "priority":
			out.Priority = int8(in.Int8())
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
func easyjsonAd788e3dEncodeModels(out *jwriter.Writer, in ScRecommend) {
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
	out.RawString("\"priority\":")
	out.Int8(int8(in.Priority))
	out.RawByte('}')
}

// MarshalJSON supports json.Marshaler interface
func (v ScRecommend) MarshalJSON() ([]byte, error) {
	w := jwriter.Writer{}
	easyjsonAd788e3dEncodeModels(&w, v)
	return w.Buffer.BuildBytes(), w.Error
}

// MarshalEasyJSON supports easyjson.Marshaler interface
func (v ScRecommend) MarshalEasyJSON(w *jwriter.Writer) {
	easyjsonAd788e3dEncodeModels(w, v)
}

// UnmarshalJSON supports json.Unmarshaler interface
func (v *ScRecommend) UnmarshalJSON(data []byte) error {
	r := jlexer.Lexer{Data: data}
	easyjsonAd788e3dDecodeModels(&r, v)
	return r.Error()
}

// UnmarshalEasyJSON supports easyjson.Unmarshaler interface
func (v *ScRecommend) UnmarshalEasyJSON(l *jlexer.Lexer) {
	easyjsonAd788e3dDecodeModels(l, v)
}
