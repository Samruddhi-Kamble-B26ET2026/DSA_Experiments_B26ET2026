#include <stdio.h>
//Without pointers
//Substring
void substring_array(char str[], char sub[], int start, int len)
{
    int i;
    for (i = 0; i < len && str[start + i] != '\0'; i++)
        sub[i] = str[start + i];
    sub[i] = '\0';
}
//Palindrome 
int palindrome_array(char str[])
{
    int i, len = 0;
    while (str[len] != '\0')
        len++;
    for (i = 0; i < len / 2; i++)
    {
        if (str[i] != str[len - 1 - i])
            return 0;
    }
    return 1;
}
//Compare
int compare_array(char str1[], char str2[])
{
    int i = 0;
    while (str1[i] != '\0' && str2[i] != '\0')
    {
        if (str1[i] != str2[i])
            return str1[i] - str2[i];
        i++;
    }
    return str1[i] - str2[i];
}
//Copy
void copy_array(char source[], char destination[])
{
    int i = 0;
    while (source[i] != '\0')
    {
        destination[i] = source[i];
        i++;
    }
    destination[i] = '\0';
}
//Reverse
void reverse_array(char str[])
{
    int i, len = 0;
    char temp;
    while (str[len] != '\0')
        len++;
    for (i = 0; i < len / 2; i++)
    {
        temp = str[i];
        str[i] = str[len - 1 - i];
        str[len - 1 - i] = temp;
    }
}
//With Pointers
//Substring
void substring_pointer(char *str, char *sub, int start, int len)
{
    int i;
    str = str + start;
    for (i = 0; i < len && *str != '\0'; i++)
    {
        *sub = *str;
        sub++;
        str++;
    }
    *sub = '\0';
}
//Palindrome 
int palindrome_pointer(char *str)
{
    char *start = str;
    char *end = str;
    while (*end != '\0')
        end++;
    end--;
    while (start < end)
    {
        if (*start != *end)
            return 0;
        start++;
        end--;
    }
    return 1;
}
//Compare
int compare_pointer(char *str1, char *str2){
    while (*str1 != '\0' && *str2 != '\0'){
        if (*str1 != *str2)
            return *str1 - *str2;
        str1++;
        str2++;
    }
    return *str1 - *str2;
}
//Copy
void copy_pointer(char *source, char *destination){
    while (*source != '\0'){
        *destination = *source;
        source++;
        destination++;
    }
    *destination = '\0';
}
//Reverse 
void reverse_pointer(char *str){
    char *start = str;
    char *end = str;
    char temp;
    while (*end != '\0')
        end++;
    end--;
    while (start < end){
        temp = *start;
        *start = *end;
        *end = temp;
        start++;
        end--;
    }}
//Main Function
int main(){
    char str1[100], str2[100];
    char sub[100], copy[100];
    printf("Enter first string: ");
    scanf("%s", str1);
    printf("Enter second string: ");
    scanf("%s", str2);
    //Without pointers
    printf("\n--- WITHOUT POINTERS ---\n");
    substring_array(str1, sub, 1, 3);
    printf("Substring: %s\n", sub);
    if (palindrome_array(str1))
        printf("Palindrome: Yes\n");
    else
        printf("Palindrome: No\n");
    printf("Compare result: %d\n", compare_array(str1, str2));
    copy_array(str1, copy);
    printf("Copied string: %s\n", copy);
    reverse_array(str1);
    printf("Reverse: %s\n", str1);
    //With pointers
    printf("\n--- WITH POINTERS ---\n");
    substring_pointer(str2, sub, 1, 3);
    printf("Substring: %s\n", sub);
    if (palindrome_pointer(str2))
        printf("Palindrome: Yes\n");
    else
        printf("Palindrome: No\n");
    printf("Compare result: %d\n", compare_pointer(str1, str2));
    copy_pointer(str2, copy);
    printf("Copied string: %s\n", copy);
    reverse_pointer(str2);
    printf("Reverse: %s\n", str2);
    return 0;
}
