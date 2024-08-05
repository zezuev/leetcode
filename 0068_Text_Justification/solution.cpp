#include <vector>
#include <string>

using namespace std;

vector<string> fullJustify(const vector<string>& words, int maxWidth) {
    vector<string> result;
    vector<string> curLine;
    int charsInCurLine = 0;

    for (const string& word: words) {
        int s = word.size();

        if (charsInCurLine + curLine.size() + s > maxWidth) {
            result.push_back(formatBlockLine(curLine, charsInCurLine, maxWidth));
            curLine.clear();
            charsInCurLine = 0;
        }

        curLine.push_back(word);
        charsInCurLine += s;
    }
    result.push_back(formatLastLine(curLine, charsInCurLine, maxWidth));

    return result;
}

string formatBlockLine(const vector<string>& line, int charsInLine, int maxWidth) {
    if (line.size() == 1) return formatLastLine(line, charsInLine, maxWidth);

    string result;
    const int numBuckets = line.size() - 1;
    const int totalSpaces = maxWidth - charsInLine;
    const int numLargeBuckets = totalSpaces % numBuckets;
    const int numSmallBuckets = numBuckets - numLargeBuckets;
    const string smallBucketSpaces = string(totalSpaces / numBuckets, ' ');

    for (int i = 0; i < line.size(); i++) {
        result += line[i];
        if (i < numBuckets) {
            result.append(smallBucketSpaces);
            if (i < numLargeBuckets) result.push_back(' ');
        }
    }
    return result;
}

string formatLastLine(const vector<string>& line, int charsInLine, int maxWidth) {
    string result;

    for (int i = 0; i < line.size(); i++) {
        result.append(line[i]);
        if (i < line.size() - 1) result.push_back(' ');
    }
    result.append(string(maxWidth - result.size(), ' '));
    return result;
}