/*
 * 535_Encode_and_Decode_TinyURL.cxx
 *
 * Copyright 2021 RedaKerouicha <redakerouicha@localhost>
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
#include <string>
#include <vector>
#include <unordered_map>

class TinyURL {
   public:
    // Encodes a URL to a shortened URL.
    std::string encode(std::string longUrl) {
        size_t h = str_hash(longUrl) >> 32;
        std::string hash = "http://tinyurl.com/" + convert_hash(h);
        // cout << hash << endl;
        m[hash] = longUrl;
        return hash;
    }

    // Decodes a shortened URL to its original URL.
    std::string decode(std::string shortUrl) { return m[shortUrl]; }

   private:
    std::unordered_map<std::string, std::string> m;
    std::hash<std::string> str_hash;
    std::string dict = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ-_";
    std::string convert_hash(size_t h) {
        std::string result = std::string{};
        while (h > 0) {
            result.push_back(dict[(h & 63)]);
            h >>= 6;
        }
        return result;
    }
};

int main(int argc, char** argv) {
    TinyURL myTinyURL;
    std::vector<std::string> tiny;
    std::vector<std::string> urls = {
        "http://www.youtube.com",   "http://www.facebook.com",  "http://www.baidu.com",    "http://www.yahoo.com",
        "http://www.amazon.com",    "http://www.wikipedia.org", "http://www.qq.com",       "http://www.google.co.in",
        "http://www.twitter.com",   "http://www.live.com",      "http://www.taobao.com",   "http://www.bing.com",
        "http://www.instagram.com", "http://www.weibo.com",     "http://www.sina.com.cn",  "http://www.linkedin.com",
        "http://www.yahoo.co.jp",   "http://www.msn.com",       "http://www.vk.com",       "http://www.google.de",
        "http://www.yandex.ru",     "http://www.hao123.com",    "http://www.google.co.uk", "http://www.reddit.com",
        "http://www.ebay.com",      "http://www.google.fr",     "http://www.t.co",         "http://www.tmall.com",
        "http://www.google.com.br", "http://www.360.cn",        "http://www.sohu.com",     "http://www.amazon.co.jp",
        "http://www.pinterest.com", "http://www.netflix.com",   "http://www.google.it",    "http://www.google.ru",
        "http://www.microsoft.com", "http://www.google.es",     "http://www.wordpress.com"};

    for (std::string v : urls) {
        tiny.push_back(myTinyURL.encode(v));
        std::cout << tiny.back() << std::endl;
    }

    for (std::string v : tiny) {
        std::cout << myTinyURL.decode(v) << std::endl;
    }

    return 0;
}
