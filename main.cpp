#include <iostream>
#include <string>

using namespace std;

class Complex{
public:
    Complex() {
        this->number = 0;
        this->inumber = 0;
    }

    [[maybe_unused]] explicit Complex(double inumber){
        this->inumber = inumber;
        this->number = 0;
    }

    Complex(double number, double inumber){
        this->number = number;
        this->inumber = inumber;
    }

    [[nodiscard]] double getNumber() const {
        return number;
    }

    [[maybe_unused]] void setNumber(double inNumber) {
        this->number = inNumber;
    }

    [[nodiscard]] double getInumber() const {
        return inumber;
    }

    [[maybe_unused]] void setInumber(double inINumber) {
        this->inumber = inINumber;
    }

    [[nodiscard]] string print() const{
        string retS;
        if(floor(this->number) == this->number){
            retS += to_string((int)this->number);
        }else{
            retS += to_string(this->number);
        }


        if(this->inumber < 0){
            retS += "-";
            if (floor(this->inumber) == this->inumber) {
                retS += to_string((int)this->inumber);
            }else{
                retS += to_string(this->inumber);
            }
            retS += "i";
        }else if(this->inumber > 0){
            retS += "+";
            if (floor(this->inumber) == this->inumber) {
                retS += to_string((int)this->inumber);
            }else{
                retS += to_string(this->inumber);
            }
            retS += "i";
        }
        return retS;
    }

    void operator ++ (){
        this->number++;
    }

    void operator ++ (int){
        this->inumber++;
    }

    void operator += (Complex num){
        this->number+=num.getNumber();
        this->inumber+=num.getInumber();
    }

    void operator -= (Complex num){
        this->number-=num.getNumber();
        this->inumber-=num.getInumber();
    }

    void operator *= (Complex num){
        this->number  = this->number * num.getNumber() - this->inumber * num.getInumber();
        this->inumber  = this->number * num.getInumber() + this->inumber  *num.getNumber();
    }

    void operator /= (Complex num){
        const double  multipler = 1/(num.getNumber()*num.getNumber()+num.getInumber()*num.getInumber());
        double tmp = num.getNumber();
        this->number = (this->number * num.getNumber() + this->inumber * num.getInumber()) * multipler;
        this->inumber = (this->inumber  * num.getNumber() - tmp * num.getInumber()) * multipler * -1;
    }

    bool operator == (Complex num) const{
        if(this->number != num.getNumber() && this->inumber != num.inumber){
            return true;
        }
        return false;
    }

    bool operator != (Complex num) const{
        if(this->number != num.getNumber() && this->inumber != num.inumber){
            return true;
        }
        return false;
    }

    bool operator < (Complex num) const{
        if(this->number > num.getNumber() && this->inumber > num.inumber){
            return true;
        }
        return false;
    }

    bool operator > (Complex num) const{
        if(this->number < num.getNumber() && this->inumber < num.inumber){
            return true;
        }
        return false;
    }

    bool operator <= (Complex num) const{
        if(this->number >= num.getNumber() && this->inumber >= num.inumber){
            return true;
        }
        return false;
    }

    bool operator >= (Complex num) const{
        if(this->number <= num.getNumber() && this->inumber <= num.inumber){
            return true;
        }
        return false;
    }

    Complex operator + (Complex num) const{
        Complex retC;
        retC.setNumber(this->number + num.getNumber());
        retC.setInumber(this->inumber + num.getInumber());
        return retC;
    }

    Complex operator - (Complex num) const{
        Complex retC;
        retC.setNumber(this->number - num.getNumber());
        retC.setInumber(this->inumber - num.getInumber());
        return retC;
    }

    Complex operator * (Complex num) const{
        Complex retC;
        retC.setNumber(this->number * num.getNumber() - this->inumber * num.getInumber());
        retC.setInumber(this->number * num.getInumber() + this->inumber  *num.getNumber());
        return retC;
    }

    Complex operator / (Complex num) const{
        Complex retC;
        const double  multipler = 1/(num.getNumber()*num.getNumber()+num.getInumber()*num.getInumber());
        retC.setNumber((this->number * num.getNumber() + this->inumber * num.getInumber()) * multipler);
        retC.setInumber((this->inumber  * num.getNumber() - num.getNumber() * num.getInumber()) * multipler * -1);
        return retC;
    }

    Complex operator ~ () const{
        Complex retC;
        retC.setNumber(this->number/(this->number * this->number + this->inumber * this->inumber));
        retC.setInumber(this->inumber/(this->number * this->number + this->inumber * this->inumber) * -1);
        return retC;
    }

private:
    double number;
    double inumber;
};

int main() {
    Complex complex = {1.5,2};
    cout<<complex.print()<<endl;
    Complex complex2 = {1,6};
    cout<<complex2.print()<<endl;
    return 0;
}
