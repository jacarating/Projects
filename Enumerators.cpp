#include <iostream>

enum class Format {Music, Movie, HardCover, PaperBack};
enum Product{CD, Book};


class Item{
  Format iFormat;
  Product iProduct;
  bool valid = false;
  public:
  Item() {}; 
  Item(enum Product x, enum Format y){
    iProduct = x;
    iFormat = y;
    valid = true;
  }

  Product getProduct()const {return iProduct;}
  Format getFormat()const {return iFormat;}
  bool isValid() const{return valid;}
};

std::ostream& operator<<(std::ostream& os, const Item& src) {
  if(src.isValid()){
  switch(src.getProduct()){
    case CD:
      os << "Product : CD |";
      if (src.getFormat() == Format::Music){
        os << " Format : Music ";
      }
      break;
    case Book:
      os << "Product : Book";
      if (src.getFormat() == Format::HardCover){
        os << " Format : HardCover";
      }
      break;
       } 

  } else os << "Empty";
  os << std::endl;
  return os;
}

int main(){
  Item test(CD, Format::Music);
  Item test2(Book, Format::HardCover);
  Item test3;
  std::cout << test;
  std::cout << test2;
  std::cout << test3;
}
