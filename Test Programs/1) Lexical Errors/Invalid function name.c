float foo@(float x){
    return x * 5.4f;
}

int main() {

    float f1 = 6.32f;
    float f2 = foo@(f1);

    return 0;
}
