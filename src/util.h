//
// Created by Juge on 3/23/26.
//

#ifndef MTAPANEL_UTIL_H
#define MTAPANEL_UTIL_H

enum class Direction
{
    N,
    S,
};

enum class Line {
    Invalid,
    One,
    Two,
    Three,
    Four,
    Five,
    Six,
    Seven,
    S,
    L,
    N,
    R,
    Q,
    W,
    B,
    D,
    F,
    M,
    A,
    C,
    E,
    J,
    Z,
    G,
};

#define COLOR_BROWN 0x8AE6
#define COLOR_BLUE 0x0319
#define COLOR_ORANGE 0xeb40
#define COLOR_LIGHTGREEN 0x7ca6
#define COLOR_DARKGREEN 0x04ca
#define COLOR_GRAY 0x7c31
#define COLOR_YELLOW 0xf5c5
#define COLOR_RED 0xd106
#define COLOR_PURPLE 0x99d4
#define COLOR_BLACK 0x0000
#define COLOR_WHITE 0xFFFF

namespace Util
{

inline uint16_t GetLineColor(Line line)
{
  switch (line)
  {
  case Line::One:
  case Line::Two:
  case Line::Three:
    return COLOR_RED;
  case Line::Four:
  case Line::Five:
  case Line::Six:
    return COLOR_DARKGREEN;
  case Line::Seven:
    return COLOR_PURPLE;
  case Line::S:
  case Line::L:
    return COLOR_GRAY;
  case Line::N:
  case Line::R:
  case Line::Q:
  case Line::W:
    return COLOR_YELLOW;
  case Line::B:
  case Line::D:
  case Line::F:
  case Line::M:
    return COLOR_ORANGE;
  case Line::A:
  case Line::C:
  case Line::E:
    return COLOR_BLUE;
  case Line::J:
  case Line::Z:
    return COLOR_BROWN;
  case Line::G:
    return COLOR_LIGHTGREEN;
  case Line::Invalid:
    break;
  }
  return COLOR_GRAY;
}

inline const char* GetLineName(Line line)
{
  switch (line)
  {
  case Line::One:
    return "1";
  case Line::Two:
    return "2";
  case Line::Three:
    return "3";
  case Line::Four:
    return "4";
  case Line::Five:
    return "5";
  case Line::Six:
    return "6";
  case Line::Seven:
    return "7";
  case Line::S:
    return "S";
  case Line::L:
    return "L";
  case Line::N:
    return "N";
  case Line::R:
    return "R";
  case Line::Q:
    return "Q";
  case Line::W:
    return "W";
  case Line::B:
    return "B";
  case Line::D:
    return "D";
  case Line::F:
    return "F";
  case Line::M:
    return "M";
  case Line::A:
    return "A";
  case Line::C:
    return "C";
  case Line::E:
    return "E";
  case Line::J:
    return "J";
  case Line::Z:
    return "Z";
  case Line::G:
    return "G";
  case Line::Invalid:
    break;
  }
  return "?";
}

inline Line GetLineFromName(const char* name)
{
  if (strcmp(name, "1") == 0)
  {
    return Line::One;
  }
  if (strcmp(name, "2") == 0)
  {
    return Line::Two;
  }
  if (strcmp(name, "3") == 0)
  {
    return Line::Three;
  }
  if (strcmp(name, "4") == 0)
  {
    return Line::Four;
  }
  if (strcmp(name, "5") == 0)
  {
    return Line::Five;
  }
  if (strcmp(name, "6") == 0)
  {
    return Line::Six;
  }
  if (strcmp(name, "7") == 0)
  {
    return Line::Seven;
  }
  if (strcmp(name, "S") == 0)
  {
    return Line::S;
  }
  if (strcmp(name, "L") == 0)
  {
    return Line::L;
  }
  if (strcmp(name, "N") == 0)
  {
    return Line::N;
  }
  if (strcmp(name, "R") == 0)
  {
    return Line::R;
  }
  if (strcmp(name, "Q") == 0)
  {
    return Line::Q;
  }
  if (strcmp(name, "W") == 0)
  {
    return Line::W;
  }
  if (strcmp(name, "B") == 0)
  {
    return Line::B;
  }
  if (strcmp(name, "D") == 0)
  {
    return Line::D;
  }
  if (strcmp(name, "F") == 0)
  {
    return Line::F;
  }
  if (strcmp(name, "M") == 0)
  {
    return Line::M;
  }
  if (strcmp(name, "A") == 0)
  {
    return Line::A;
  }
  if (strcmp(name, "C") == 0)
  {
    return Line::C;
  }
  if (strcmp(name, "E") == 0)
  {
    return Line::E;
  }
  if (strcmp(name, "J") == 0)
  {
    return Line::J;
  }
  if (strcmp(name, "Z") == 0)
  {
    return Line::Z;
  }
  if (strcmp(name, "G") == 0)
  {
    return Line::G;
  }
  return Line::Invalid;
}

inline const char* ParseDirectionWithLine(Direction direction, Line line)
{
  switch (line)
  {
  case Line::Invalid:
    return "???";
  case Line::One:
  case Line::Two:
  case Line::Three:
  case Line::Four:
  case Line::Five:
  case Line::Six:
    return direction == Direction::N ? "BRX" : "DT";
  case Line::Seven:
    return direction == Direction::N ? "QNS" : "MAN";
  case Line::S:
    return direction == Direction::N ? "N" : "S";
  case Line::L:
    return direction == Direction::N ? "MAN" : "BRK";
  case Line::N:
  case Line::R:
  case Line::W:
  case Line::Q:
    return direction == Direction::N ? "MAN" : "BRK";
  case Line::B:
  case Line::D:
    return direction == Direction::N ? "MAN" : "BRK";
  case Line::M:
    return direction == Direction::N ? "MAN" : "QNS"; // This seems like it should be reversed, but its correct
  case Line::F:
    return direction == Direction::N ? "QNS" : "BRK";
  case Line::A:
  case Line::C:
  case Line::E:
    return direction == Direction::N ? "MAN" : "QNS";
  case Line::J:
  case Line::Z:
    return direction == Direction::N ? "QNS" : "MAN";
  case Line::G:
    return direction == Direction::N ? "QNS" : "BRK";
  }
  return "";
}

inline String EllipsizeName(const String& s, size_t maxLen)
{
  if (s.length() <= maxLen) return s;
  if (maxLen <= 3) return s.substring(0, maxLen);
  return s.substring(0, maxLen - 3) + "...";
}

}

#endif //MTAPANEL_UTIL_H