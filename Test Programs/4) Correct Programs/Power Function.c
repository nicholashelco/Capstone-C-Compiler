int pow(int x, int p){

    if(p <= 0)
        return 1;

    else{

        int result = x;

        for(int i=0; i<p-1; i++)
            result *= x;

        return result;
    }
}

int main() {

    int base = 6;
    int power = 2;

    int squ = pow(base, power);

    return 0;
}
