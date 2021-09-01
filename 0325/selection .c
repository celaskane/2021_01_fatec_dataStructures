void selection_sort(int *v, int n){
    int i, j, menor, x; // 2 4 6 1
    for (i = 0; i < n - 1; i++){
        menor = i;
        x = v[i];
        for(j = i + 1; j < n; j++){
            if(v[j] < v[menor]){
                menor = j;
            }
        }
        v[i] = v[menor];
        v[menor] = x;

    }

}