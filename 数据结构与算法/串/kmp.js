/*

kmp

*/

/**
 * @param {string} s 待匹配字符串
 * @returns {Array} next数组
 */
function get_next(s) {
    let next = new Array(s.length);
    next[0] = -1;
    for (let i = 1; i < next.length; i++) {
        let idx = next[i - 1];
        while (idx >= 0 && s[idx] != s[i - 1])
            idx = next[idx];
        next[i] = idx + 1;
    }
    return next;
}

/**
 * @param {string} str 待匹配原串
 * @param {string} s 待匹配字符串
 * @returns {number} 待匹配字符串在原串中的开始索引，不存在则返回-1
 */
function kmp(str, s) {
    let next = get_next(s);
    let stri = 0, si = 0;
    while (stri < str.length && si < s.length)
        if (str[stri] === s[si] || (si = next[si]) === -1)
            stri++, si++;
    return si >= s.length ? stri - s.length : -1;
}

function main() {
    let str = "googlgooggg", s = "google";
    console.log(kmp(str, s));

    str = "asadgffege", s = "adg";
    console.log(kmp(str, s));
}

main();