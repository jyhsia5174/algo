/*
L   l   r   m
1   0   0   0   0   -1   1   0
2   0   1   0   0   -1   1   1
3   0   2   1   0   0   2   2
*/

vector<int> A(n);
int l = 0, r = n-1;
while( (r-l) >= 0 ){
    int m = l + (r - l) / 2;
  
    if( criteria(m) ){
        l = m+1;
    }
    else{
        r = m+1;
    }
}

// r + 1 == l 

/*
L   l   r   m
2   0   2   1   0   1   1   2
3   0   3   1   0   1   1   3
*/

int l = 0, r = n;
while( l < r ){
    int m = l + (r - l) / 2;
    
    if( criteria(m) ){
        l = m;
    }
    else{
        r = m;
    }
}

// at break l + 1 == r


/*
L   l   r   m
3   0   2   1   0   1   1   2
4   0   3   1   0   1   1   3
*/

int l = 0, r = n-1;
while( l + 1 < r ){
    int m = l + (r - l) / 2;
    if( criteria(m) ){
        l = m;
    }
    else{
        r = m;
    }
}

// at break l + 1 == r;
