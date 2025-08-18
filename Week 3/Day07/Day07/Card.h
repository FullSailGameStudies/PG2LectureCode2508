#pragma once
#include <string>

enum CardFace
{
	A = 1, Two, Three, Four, Five, Six, Seven, Eight, Nine, Ten, Jack, Queen, King
};
class Card
{
public:
	Card(const CardFace& face, const std::string& suit)
		: face_(face), suit_(suit)
	{
	}

	const CardFace& Face() const { return face_; }
	void Face(const CardFace& face)
	{
		//if (face == "A" || face == "2" || face == "3" || face == "4" ||
		//	face == "5" || face == "6" || face == "7" ||
		//	face == "8" || face == "9" || face == "10" ||
		//	face == "J" || face == "Q" || face == "K")
		if(face >= CardFace::A && face <= CardFace::King)
		{
			face_ = face;
		}
	}

	const std::string& Suit() const { return suit_; }
	void Suit(const std::string& suit)
	{
		if (suit == "Hearts" || suit == "Diamonds" || suit == "Spades" ||
			suit == "Clubs")
		{
			suit_ = suit;
		}
	}

	void Print() const;
	int Value() const;

private:
	std::string suit_;
	CardFace face_;

};

