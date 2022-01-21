package main

import (
        "log"
)

// Figure represents the behavior of a geometric figure.
type Figure interface {
  Move()
  Rotate()
}

// Point represent a coordinate.
type Point struct {
  X int
  Y int
}

// Move allows a Point to change its coordinates.
func (p *Point) Move() {
  log.Printf("Point{%d, %d} moved\n", p.X, p.Y)
}

// Rotate will rotate the point.
func (p *Point) Rotate() {
  log.Printf("Point{%d, %d} rotated\n", p.X, p.Y)
}

// Line consists of two coordinates.
type Line struct {
  A Point
  B Point
}

// Move will move the line.
func (l *Line) Move() {
  log.Printf("Line{%v, %v} moved\n", l.A, l.B)
}

// Rotate will rotate the line.
func (l *Line) Rotate() {
  log.Printf("Line{%v, %v} rotated\n", l.A, l.B)
}

type Circle struct {
  Center Point
  Radius int
}

// Move will move the circle.
func (c *Circle) Move() {
  log.Printf("Circle{%v, %d} moved\n", c.Center, c.Radius)
}

// Rotate will rotate the circle.
func (c *Circle) Rotate() {
  log.Printf("Circle{%v, %d} rotated\n", c.Center, c.Radius)
}

// Aggregation ...
type Aggregation struct {
  Figures []Figure
}

// Move will move all the figures
func (a *Aggregation) Move() {
  for _, figure := range a.Figures {
    figure.Move()
  }
}

// Rotate will rotate all the figures
func (a *Aggregation) Rotate() {
  for _, figure := range a.Figures {
    figure.Rotate()
  }
}

func main() {
  a := Aggregation{
    []Figure{&Point{0, 0}, &Line{}, &Circle{}},
  }

  a.Move()
}
