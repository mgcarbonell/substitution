#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>


bool is_valid(string s);

int main(int argc, string argv[])
{
    // count number of args from user
    if (argc != 2)
    {
        printf("uesage: ./substitution key\n");
        return 1;
    }

    // make sure they put in 26 alphabet characters
    if (!is_valid(argv[1]))
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }

    string s = get_string("plaintext: ");
    string diff = argv[1];
    for (int i = 'A'; i <= 'Z'; i++)
    {
        diff[i - 'A'] = toupper(diff[i - 'A']) - i;
    }
    printf("ciphertext: ");
    // calculate the difference between the position
    for (int i = 0, len = strlen(s); i < len; i++)
    {
        if (isalpha(s[i]))
        {
            // now we need to take the char and add the corresponding difference
            s[i] = s[i] + diff[s[i] - (isupper(s[i]) ? 'A' : 'a')];
        }
        // print s[i] after being converted, we'll store in %c
        printf("%c", s[i]);
    }
    printf("\n");
    return 0;
}

bool is_valid(string s)
{
    int len = strlen(s);
    if (len != 26)
    {
        return false;
    }
    // see if a letter has been used twice.
    // we set a frequency, an array of 26 and fill it with 0s
    // as we iterate through the array, we set the values and
    // then check the previous value. If the value repeats,
    // return false.
    int freq[26] = {0};
    for (int i = 0; i < len; i++)
    {
        if(!isalpha(s[i]))
        {
            return false;
        }

        int index = toupper(s[i]) - 'A';
        if (freq[index] > 0)
        {
            return false;
        }
        freq[index]++;
    }

    return true;
}