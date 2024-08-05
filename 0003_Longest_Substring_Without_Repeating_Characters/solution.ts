function lengthOfLongestSubstring(s: string): number {
    let arr = Array<number>(128).fill(0);
    let start = 0;
    let max = 0;

    for (let end = 0; end < s.length; end++) {
        let endCode = s.charCodeAt(end);
        while (arr[endCode] > 0) {
            let startCode = s.charCodeAt(start);
            arr[startCode]--;
            start++;
        }
        arr[endCode]++;
        max = Math.max(max, end - start + 1);
    }
    return max;
}