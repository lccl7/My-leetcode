int computeArea(int A, int B, int C, int D, int E, int F, int G, int H)
{
    int s1 = (C - A)*(D - B);
    int s2 = (G - E)*(H - F);
    int s3 = (min(C, G) - max(A, E))*(min(D, H) - max(B, F));
    if(A >= G || C <= E || B >= H || D <= F)
        return s1 + s2;
    return s1 + s2 - s3;
}
