int reverse(int x){
    long long newX = 0;

    while (x != 0) {
        newX = (newX * 10) + (x % 10);
        x = x / 10;
    }
    
    if (newX <= pow(-2, 31) || newX >= (pow(2, 31) - 1))
    {
        return 0;
    }

    return (int)newX;
}