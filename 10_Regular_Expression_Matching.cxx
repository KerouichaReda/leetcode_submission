/*
 * 10_Regular_Expression_Matching.cxx
 * 
 * Copyright 2020 RedaKerouicha <redakerouicha@localhost>
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 * 
 * 
 */


#include <iostream>
/*
 * bool isMatch(string s, string p) {
    int n = s.size();
    int m = p.size();
    if(n == 0 && m == 0) 
        return true;
    if(m == 0) 
        return false;
    vector<vector<bool>> dp(n+1, vector<bool>(m+1, false)); 
    dp[0][0] = true; 
    for(int j=2; j<=m; j++) 
        dp[0][j] = dp[0][j-2] && p[j-1]=='*';
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            if(p[j-1] >= 'a' && p[j-1] <= 'z') dp[i][j] = dp[i-1][j-1] && (bool)(s[i-1]==p[j-1]);
            else if(p[j-1] == '.') 
                dp[i][j] = dp[i-1][j-1];
            else if(j > 1) {
                if(s[i-1] == p[j-2] || p[j-2] == '.') 
                    dp[i][j] = dp[i-1][j] | dp[i][j-2];
                else 
                    dp[i][j] = dp[i][j-2];
            }
        }
    }
    return dp[n][m];    
}
};*/
using namespace std;
bool matchhere(char *regexp, char *text);
bool matchstar(char c, char *regexp, char *text);

/* match: search for regexp anywhere in text */
bool match(char *regexp, char *text)
{	
	do 
	{    /* must look even if string is empty */
		if (matchhere(regexp, text))
		{
			return true;
		}
	} 
	while (*text++ != '\0' && *regexp++!='\0');
	
	return false;
}

/* matchhere: search for regexp at beginning of text */
bool matchhere(char *regexp, char *text)
{
	//empty reg
	if (regexp[0] == '\0')
	{		
		return text[0]=='\0';
	}
	//looking for the star matching	
	if (regexp[1] == '*')
	{
		std::cout<<"*:"<<regexp<<" "<<text<<std::endl;
		return matchstar(regexp[0], regexp+2, text);	
	}
	if (*text!='\0' && (regexp[0]=='.' || regexp[0]==*text))
	{
		std::cout<<"=:"<<regexp<<" "<<text<<std::endl;
		return matchhere(regexp+1, text+1);
	}	
		
	return false;
}

/* matchstar: search for c*regexp at beginning of text */
bool matchstar(char c, char *regexp, char *text)
{
	char *t;

	for (t = text; *t != '\0' && (*t == c || c == '.'); t++);
	do 
	{    /* a * matches zero or more instances */
		if (matchhere(regexp, t))
			return true;
		std::cout<<"**l:"<<regexp<<" "<<text<<" "<<c<<std::endl;
	} 
	while (t-- > text);
	//std::cout<<"**:"<<regexp<<" "<<text<<" "<<c<<std::endl;
	return false;
}


int main(int argc, char **argv)
{
	char reg[]="ab*a*c*d";
	char text[]="aabd";



	std::cout<<match(reg, text)<<std::endl;
	return 0;
}

