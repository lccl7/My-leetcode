//for each number, if the operator before it is '+' or '-',
//we should calculate the term of the current number and the sign of it.
//else if the operator is '*' or '/', we can calculate the current number with
//the number before it.
int calculate(string s) {
    istringstream in('+' + s + '+');
    long long total = 0, term = 0, n;
    char op;
    while (in >> op) {
        if (op == '+' || op == '-')
        {
            total += term;
            in >> term;
            term *= 44 - op;
        }
        else
        {
            in >> n;
            if (op == '*')
                term *= n;
            else
                term /= n;
        }
    }
    return total;
}

int main(int argc, char** argv)
{
    ifstream infile(argv[1]);
    string s;
    while(getline(infile, s))
    {
        cout << calculate(s) << endl;
    }
}
