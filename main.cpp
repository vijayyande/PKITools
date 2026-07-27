#ifndef UNICODE
#define UNICODE
#define _UNICODE
#endif

#define WINVER 0x0A00
#define _WIN32_WINNT 0x0A00
#define NTDDI_VERSION 0x0A00000A

#include <windows.h>
#include <commctrl.h>
#include <commdlg.h>
#include <bcrypt.h>
#include <ncrypt.h>
#include <wincrypt.h>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <locale>

#ifndef NT_SUCCESS
#define NT_SUCCESS(Status) (((NTSTATUS)(Status)) >= 0)
#endif

#pragma comment(lib, "bcrypt.lib")
#pragma comment(lib, "ncrypt.lib")
#pragma comment(lib, "crypt32.lib")
#pragma comment(lib, "comdlg32.lib")
#pragma comment(lib, "comctl32.lib")
#pragma comment(lib, "shell32.lib")
#pragma comment(lib, "user32.lib")
#pragma comment(lib, "gdi32.lib")
#pragma comment(lib, "kernel32.lib")
#pragma comment(linker, "/MANIFESTDEPENDENCY:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='*' publicKeyToken='6595b64144ccf1df' language='*'\"")

// ===== Control IDs =====
#define ID_INPUT_EDIT   1001
#define ID_OUTPUT_EDIT  1002
#define ID_CLEAR_BTN    1005
#define ID_SWAP_BTN     1006

#define ID_MENU_EXIT               2011
#define ID_MENU_ABOUT              2012
#define ID_MENU_COPY_OUTPUT        2013
#define ID_MENU_PASTE_INPUT        2014
#define ID_MENU_CLEAR_BOTH         2015
#define ID_MENU_FILE_OPEN          2017
#define ID_MENU_FILE_SAVE          2018

#define ID_MENU_KEYGEN_RSA         3001
#define ID_MENU_KEYGEN_ECDSA       3002
#define ID_MENU_KEYGEN_ECDH        3003
#define ID_MENU_KEYGEN_DSA         3004
#define ID_MENU_KEYGEN_DH          3005
#define ID_MENU_KEYGEN_AES         3006
#define ID_MENU_KEYGEN_3DES        3007
#define ID_MENU_KEYGEN_CHACHA20    3008
#define ID_MENU_KEYGEN_RANDOM      3009
#define ID_MENU_ENCODING_DIALOG    3010
#define ID_MENU_CSR                3011
#define ID_MENU_PKCS7              3012
#define ID_MENU_CA_CERT            3013
#define ID_MENU_SIGN_CERT          3014
#define ID_MENU_TLS_CERT           3015
#define ID_MENU_SERVER_CERT         3016
#define ID_MENU_USER_CERT           3017
#define ID_MENU_SELF_CERT           3018
#define ID_MENU_PKCS12              3019

#define IDC_COMBO_PARAM            4001
#define IDC_COMBO_PARAM2           4002
#define IDC_BTN_GENERATE           4003
#define IDC_BTN_CANCEL             4004
#define IDC_STATIC_INFO            4005

// Encoding dialog controls
#define IDC_COMBO_ENCODING         5001
#define IDC_ENCODE_BTN             5002
#define IDC_DECODE_BTN             5003
#define IDC_ENC_INPUT              5004
#define IDC_ENC_OUTPUT             5005
#define IDC_ENC_COPY_BTN           5006
#define IDC_ENC_SWAP_BTN           5007

// CSR dialog controls
#define IDC_CSR_CN                 6001
#define IDC_CSR_ORG                6002
#define IDC_CSR_OU                 6003
#define IDC_CSR_LOCALITY           6004
#define IDC_CSR_STATE              6005
#define IDC_CSR_COUNTRY            6006
#define IDC_CSR_EMAIL              6007
#define IDC_CSR_KEYTYPE            6008
#define IDC_CSR_KEYSIZE            6009
#define IDC_CSR_GENERATE           6010
#define IDC_CSR_CANCEL             6011
#define IDC_CSR_SANS               6012

// PKCS7 dialog controls
#define IDC_PKCS7_INPUT            7001
#define IDC_PKCS7_CREATE_BTN       7002
#define IDC_PKCS7_CANCEL_BTN       7003

// CA cert dialog controls
#define IDC_CA_CN                  8001
#define IDC_CA_ORG                 8002
#define IDC_CA_OU                  8003
#define IDC_CA_LOCALITY            8004
#define IDC_CA_STATE               8005
#define IDC_CA_COUNTRY             8006
#define IDC_CA_EMAIL               8007
#define IDC_CA_KEYTYPE             8008
#define IDC_CA_VALIDITY            8009
#define IDC_CA_GENERATE            8010
#define IDC_CA_CANCEL              8011

// CA-signed cert dialog controls
#define IDC_SIGN_CN                9001
#define IDC_SIGN_ORG               9002
#define IDC_SIGN_OU                9003
#define IDC_SIGN_LOCALITY          9004
#define IDC_SIGN_STATE             9005
#define IDC_SIGN_COUNTRY           9006
#define IDC_SIGN_EMAIL             9007
#define IDC_SIGN_KEYTYPE           9008
#define IDC_SIGN_VALIDITY          9009
#define IDC_SIGN_CA_CERT           9010
#define IDC_SIGN_CA_CERT_BROWSE    9011
#define IDC_SIGN_CA_KEY            9012
#define IDC_SIGN_CA_KEY_BROWSE     9013
#define IDC_SIGN_GENERATE          9014
#define IDC_SIGN_CANCEL            9015

// TLS/Server/User cert dialog controls
#define IDC_TLS_TYPE               10001
#define IDC_TLS_CN                 10002
#define IDC_TLS_ORG                10003
#define IDC_TLS_OU                 10004
#define IDC_TLS_LOCALITY           10005
#define IDC_TLS_STATE              10006
#define IDC_TLS_COUNTRY            10007
#define IDC_TLS_EMAIL              10008
#define IDC_TLS_SAN                10009
#define IDC_TLS_KEYTYPE            10010
#define IDC_TLS_VALIDITY           10011
#define IDC_TLS_CA_CERT            10012
#define IDC_TLS_CA_CERT_BROWSE     10013
#define IDC_TLS_CA_KEY             10014
#define IDC_TLS_CA_KEY_BROWSE      10015
#define IDC_TLS_GENERATE           10016
#define IDC_TLS_CANCEL             10017

#define IDC_SELF_TYPE              11001
#define IDC_SELF_CN                11002
#define IDC_SELF_ORG               11003
#define IDC_SELF_OU                11004
#define IDC_SELF_LOCALITY          11005
#define IDC_SELF_STATE             11006
#define IDC_SELF_COUNTRY           11007
#define IDC_SELF_EMAIL             11008
#define IDC_SELF_SAN               11009
#define IDC_SELF_KEYTYPE           11010
#define IDC_SELF_VALIDITY          11011
#define IDC_SELF_GENERATE          11012
#define IDC_SELF_CANCEL            11013

#define IDC_P12_MODE               12001
#define IDC_P12_FILE               12002
#define IDC_P12_FILE_BROWSE        12003
#define IDC_P12_PASSWORD           12004
#define IDC_P12_CERT_FILE          12005
#define IDC_P12_CERT_BROWSE        12006
#define IDC_P12_KEY_FILE           12007
#define IDC_P12_KEY_BROWSE         12008
#define IDC_P12_LIST               12009
#define IDC_P12_ADD_CERT           12010
#define IDC_P12_ADD_KEY            12011
#define IDC_P12_SAVE               12012
#define IDC_P12_CANCEL             12013
#define IDC_P12_REMOVE             12014

#define IDC_PKCS7_BROWSE_BTN       7004
#define IDC_PKCS7_FILE_EDIT        7005

// ===== Globals =====
static HWND hInputEdit = NULL;
static HWND hOutputEdit = NULL;
static HWND hClearBtn = NULL;
static HWND hSwapBtn = NULL;
static HWND hStatusLabel = NULL;
static HWND hModeLabel = NULL;

static HFONT hFont = NULL;
static HFONT hBoldFont = NULL;
static HINSTANCE g_hInstance = NULL;

// ===== String Helpers =====
std::string WstringToUtf8(const std::wstring& wstr) {
    if (wstr.empty()) return "";
    int size = WideCharToMultiByte(CP_UTF8, 0, wstr.c_str(), (int)wstr.size(), NULL, 0, NULL, NULL);
    std::string result(size, 0);
    WideCharToMultiByte(CP_UTF8, 0, wstr.c_str(), (int)wstr.size(), &result[0], size, NULL, NULL);
    return result;
}

std::wstring Utf8ToWstring(const std::string& str) {
    if (str.empty()) return L"";
    int size = MultiByteToWideChar(CP_UTF8, 0, str.c_str(), (int)str.size(), NULL, 0);
    std::wstring result(size, 0);
    MultiByteToWideChar(CP_UTF8, 0, str.c_str(), (int)str.size(), &result[0], size);
    return result;
}

std::wstring GetEditText(HWND hwnd) {
    int len = GetWindowTextLengthW(hwnd);
    if (len == 0) return L"";
    std::wstring buf(len + 1, L'\0');
    GetWindowTextW(hwnd, &buf[0], len + 1);
    buf.resize(len);
    return buf;
}

void SetEditText(HWND hwnd, const std::wstring& text) {
    SetWindowTextW(hwnd, text.c_str());
}

void SetStatus(const std::wstring& text) {
    if (hStatusLabel) SetWindowTextW(hStatusLabel, text.c_str());
}

std::string BytesToHex(const BYTE* data, size_t len) {
    std::ostringstream oss;
    for (size_t i = 0; i < len; i++) {
        oss << std::hex << std::uppercase << std::setw(2) << std::setfill('0') << (int)data[i];
    }
    return oss.str();
}

std::string BytesToBase64(const BYTE* data, size_t len) {
    static const char table[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
    std::string ret;
    ret.reserve(((len + 2) / 3) * 4);
    for (size_t i = 0; i < len; i += 3) {
        unsigned int n = ((unsigned int)data[i]) << 16;
        if (i + 1 < len) n |= ((unsigned int)data[i + 1]) << 8;
        if (i + 2 < len) n |= ((unsigned int)data[i + 2]);
        ret.push_back(table[(n >> 18) & 0x3F]);
        ret.push_back(table[(n >> 12) & 0x3F]);
        ret.push_back((i + 1 < len) ? table[(n >> 6) & 0x3F] : '=');
        ret.push_back((i + 2 < len) ? table[n & 0x3F] : '=');
    }
    return ret;
}

std::string WrapPem(const std::string& b64, const char* label) {
    std::string pem = "-----BEGIN " + std::string(label) + "-----\r\n";
    for (size_t i = 0; i < b64.size(); i += 64) {
        pem += b64.substr(i, 64) + "\r\n";
    }
    pem += "-----END " + std::string(label) + "-----";
    return pem;
}

std::string WrapLines(const std::string& text, int lineLen) {
    std::string result;
    for (size_t i = 0; i < text.size(); i += lineLen) {
        if (i > 0) result += "\r\n";
        result += text.substr(i, lineLen);
    }
    return result;
}

// ===== ENCODING/DECODING =====
static const std::string base64_chars =
    "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

std::string base64_encode(const std::string& input) {
    std::string ret;
    int val = 0, valb = -6;
    for (unsigned char c : input) {
        val = (val << 8) + c; valb += 8;
        while (valb >= 0) { ret.push_back(base64_chars[(val >> valb) & 0x3F]); valb -= 6; }
    }
    if (valb > -6) ret.push_back(base64_chars[((val << 8) >> (valb + 8)) & 0x3F]);
    while (ret.size() % 4) ret.push_back('=');
    return ret;
}

std::string base64_decode(const std::string& input) {
    std::vector<int> T(256, -1);
    for (int i = 0; i < 64; i++) T[base64_chars[i]] = i;
    std::string ret; int val = 0, valb = -8;
    for (unsigned char c : input) {
        if (T[c] == -1) break;
        val = (val << 6) + T[c]; valb += 6;
        if (valb >= 0) { ret.push_back(char((val >> valb) & 0xFF)); valb -= 8; }
    }
    return ret;
}

std::string hex_encode(const std::string& input) {
    std::ostringstream oss;
    for (unsigned char c : input)
        oss << std::hex << std::uppercase << std::setw(2) << std::setfill('0') << (int)c;
    return oss.str();
}

std::string hex_decode(const std::string& input) {
    std::string clean;
    for (char c : input)
        if (!isspace((unsigned char)c)) clean.push_back(c);
    if (clean.size() % 2 != 0) clean = "0" + clean;
    std::string ret;
    for (size_t i = 0; i < clean.size(); i += 2)
        ret.push_back((char)strtol(clean.substr(i, 2).c_str(), NULL, 16));
    return ret;
}

std::string url_encode(const std::string& input) {
    std::ostringstream oss;
    for (unsigned char c : input) {
        if (isalnum(c) || c == '-' || c == '_' || c == '.' || c == '~') oss << (char)c;
        else oss << '%' << std::hex << std::uppercase << std::setw(2) << std::setfill('0') << (int)c;
    }
    return oss.str();
}

std::string url_decode(const std::string& input) {
    std::string ret;
    for (size_t i = 0; i < input.size(); i++) {
        if (input[i] == '%' && i + 2 < input.size()) {
            int val; std::istringstream iss(input.substr(i + 1, 2));
            iss >> std::hex >> val; ret.push_back((char)val); i += 2;
        } else if (input[i] == '+') ret.push_back(' ');
        else ret.push_back(input[i]);
    }
    return ret;
}

std::string binary_encode(const std::string& input) {
    std::string ret;
    for (size_t i = 0; i < input.size(); i++) {
        if (i > 0) ret += " ";
        for (int b = 7; b >= 0; b--)
            ret += ((unsigned char)input[i] >> b) & 1 ? '1' : '0';
    }
    return ret;
}

std::string binary_decode(const std::string& input) {
    std::string clean;
    for (char c : input) if (c == '0' || c == '1') clean.push_back(c);
    std::string ret;
    for (size_t i = 0; i + 8 <= clean.size(); i += 8) {
        char byte = 0;
        for (int b = 0; b < 8; b++) byte = (byte << 1) | (clean[i + b] - '0');
        ret.push_back(byte);
    }
    return ret;
}

std::string unicode_escape_encode(const std::string& input) {
    std::wstring wstr = Utf8ToWstring(input);
    std::ostringstream oss;
    for (wchar_t wc : wstr) {
        if (wc <= 0x7F) oss << (char)wc;
        else oss << "\\u" << std::hex << std::uppercase << std::setw(4) << std::setfill('0') << (int)wc;
    }
    return oss.str();
}

std::string unicode_escape_decode(const std::string& input) {
    std::wstring result;
    for (size_t i = 0; i < input.size(); ) {
        if (input[i] == '\\' && i + 5 < input.size() && (input[i+1] == 'u' || input[i+1] == 'U')) {
            int len = (input[i+1] == 'U') ? 8 : 4;
            if (i + 1 + len <= input.size()) {
                std::string hexStr = input.substr(i + 2, len);
                result += (wchar_t)strtol(hexStr.c_str(), NULL, 16);
                i += 2 + len;
            } else { result += input[i]; i++; }
        } else if (input[i] == '\\' && i + 1 < input.size() && input[i+1] == 'n') { result += L'\n'; i += 2; }
        else if (input[i] == '\\' && i + 1 < input.size() && input[i+1] == 't') { result += L'\t'; i += 2; }
        else { result += (wchar_t)(unsigned char)input[i]; i++; }
    }
    return WstringToUtf8(result);
}

// ===== ENCODING DIALOG =====
struct EncDlgCtx {
    HWND hCombo;
    HWND hInput;
    HWND hOutput;
    HWND hEncodeBtn;
    HWND hDecodeBtn;
    HWND hCopyBtn;
    HWND hSwapBtn;
};

static const wchar_t ENC_DLG_CLASS[] = L"EncDialogClass";
static bool encDlgClassRegistered = false;

LRESULT CALLBACK EncDlgProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
    EncDlgCtx* ctx = NULL;
    if (msg == WM_NCCREATE) {
        ctx = (EncDlgCtx*)((CREATESTRUCTW*)lParam)->lpCreateParams;
        SetWindowLongPtr(hwnd, GWLP_USERDATA, (LONG_PTR)ctx);
        return DefWindowProcW(hwnd, msg, wParam, lParam);
    }
    ctx = (EncDlgCtx*)GetWindowLongPtr(hwnd, GWLP_USERDATA);

    switch (msg) {
    case WM_CREATE: {
        HFONT hf = hBoldFont ? hBoldFont : (HFONT)GetStockObject(DEFAULT_GUI_FONT);
        HFONT hnf = hFont ? hFont : (HFONT)GetStockObject(SYSTEM_FONT);

        CreateWindowW(L"STATIC", L"Encoding:",
            WS_CHILD | WS_VISIBLE, 10, 10, 60, 20, hwnd, NULL, NULL, NULL);

        ctx->hCombo = CreateWindowExW(0, L"COMBOBOX", L"",
            WS_CHILD | WS_VISIBLE | WS_BORDER | CBS_DROPDOWNLIST | WS_VSCROLL,
            80, 7, 180, 120, hwnd, (HMENU)(INT_PTR)IDC_COMBO_ENCODING, NULL, NULL);
        SendMessage(ctx->hCombo, WM_SETFONT, (WPARAM)hf, TRUE);
        const wchar_t* modes[] = { L"Base64", L"Hex", L"URL Encoding", L"Binary", L"Unicode Escape" };
        for (auto m : modes) SendMessageW(ctx->hCombo, CB_ADDSTRING, 0, (LPARAM)m);
        SendMessageW(ctx->hCombo, CB_SETCURSEL, 0, 0);

        CreateWindowW(L"STATIC", L"Input:",
            WS_CHILD | WS_VISIBLE, 10, 38, 60, 20, hwnd, NULL, NULL, NULL);

        ctx->hInput = CreateWindowExW(WS_EX_CLIENTEDGE, L"EDIT", L"",
            WS_CHILD | WS_VISIBLE | WS_VSCROLL | WS_HSCROLL | ES_MULTILINE | ES_AUTOVSCROLL,
            10, 58, 540, 120, hwnd, (HMENU)(INT_PTR)IDC_ENC_INPUT, NULL, NULL);
        SendMessage(ctx->hInput, WM_SETFONT, (WPARAM)hnf, TRUE);

        int btnX = 560;
        ctx->hEncodeBtn = CreateWindowW(L"BUTTON", L"Encode >>",
            WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
            btnX, 58, 95, 30, hwnd, (HMENU)(INT_PTR)IDC_ENCODE_BTN, NULL, NULL);
        SendMessage(ctx->hEncodeBtn, WM_SETFONT, (WPARAM)hf, TRUE);

        ctx->hDecodeBtn = CreateWindowW(L"BUTTON", L"<< Decode",
            WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
            btnX, 95, 95, 30, hwnd, (HMENU)(INT_PTR)IDC_DECODE_BTN, NULL, NULL);
        SendMessage(ctx->hDecodeBtn, WM_SETFONT, (WPARAM)hf, TRUE);

        ctx->hSwapBtn = CreateWindowW(L"BUTTON", L"Swap",
            WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
            btnX, 132, 95, 22, hwnd, (HMENU)(INT_PTR)IDC_ENC_SWAP_BTN, NULL, NULL);
        SendMessage(ctx->hSwapBtn, WM_SETFONT, (WPARAM)hf, TRUE);

        ctx->hCopyBtn = CreateWindowW(L"BUTTON", L"Copy Out",
            WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
            btnX, 158, 95, 22, hwnd, (HMENU)(INT_PTR)IDC_ENC_COPY_BTN, NULL, NULL);
        SendMessage(ctx->hCopyBtn, WM_SETFONT, (WPARAM)hf, TRUE);

        CreateWindowW(L"STATIC", L"Output:",
            WS_CHILD | WS_VISIBLE, 10, 185, 60, 20, hwnd, NULL, NULL, NULL);

        ctx->hOutput = CreateWindowExW(WS_EX_CLIENTEDGE, L"EDIT", L"",
            WS_CHILD | WS_VISIBLE | WS_VSCROLL | WS_HSCROLL | ES_MULTILINE | ES_AUTOVSCROLL | ES_READONLY,
            10, 205, 645, 120, hwnd, (HMENU)(INT_PTR)IDC_ENC_OUTPUT, NULL, NULL);
        SendMessage(ctx->hOutput, WM_SETFONT, (WPARAM)hnf, TRUE);
        return 0;
    }
    case WM_COMMAND:
        if (ctx) {
            if (LOWORD(wParam) == IDC_ENCODE_BTN || LOWORD(wParam) == IDC_DECODE_BTN) {
                bool encode = (LOWORD(wParam) == IDC_ENCODE_BTN);
                int mode = (int)SendMessageW(ctx->hCombo, CB_GETCURSEL, 0, 0);
                std::wstring input = GetEditText(ctx->hInput);
                if (input.empty()) { SetStatus(L"Input is empty."); return 0; }
                try {
                    std::string utf8 = WstringToUtf8(input);
                    std::string result;
                    if (encode) {
                        switch (mode) {
                            case 0: result = base64_encode(utf8); break;
                            case 1: result = hex_encode(utf8); break;
                            case 2: result = url_encode(utf8); break;
                            case 3: result = binary_encode(utf8); break;
                            case 4: result = unicode_escape_encode(utf8); break;
                        }
                    } else {
                        switch (mode) {
                            case 0: result = base64_decode(utf8); break;
                            case 1: result = hex_decode(utf8); break;
                            case 2: result = url_decode(utf8); break;
                            case 3: result = binary_decode(utf8); break;
                            case 4: result = unicode_escape_decode(utf8); break;
                        }
                    }
                    SetEditText(ctx->hOutput, Utf8ToWstring(result));
                    const wchar_t* names[] = { L"Base64", L"Hex", L"URL", L"Binary", L"Unicode" };
                    SetStatus((encode ? L"Encoded" : L"Decoded") + std::wstring(L" using ") + names[mode] + L".");
                } catch (...) { SetStatus(L"Operation failed."); }
                return 0;
            }
            if (LOWORD(wParam) == IDC_ENC_SWAP_BTN) {
                std::wstring output = GetEditText(ctx->hOutput);
                SetEditText(ctx->hInput, output);
                return 0;
            }
            if (LOWORD(wParam) == IDC_ENC_COPY_BTN) {
                std::wstring text = GetEditText(ctx->hOutput);
                if (!text.empty() && OpenClipboard(NULL)) {
                    EmptyClipboard();
                    size_t sz = (text.size() + 1) * sizeof(wchar_t);
                    HGLOBAL hMem = GlobalAlloc(GMEM_MOVEABLE, sz);
                    if (hMem) { memcpy(GlobalLock(hMem), text.c_str(), sz); GlobalUnlock(hMem); SetClipboardData(CF_UNICODETEXT, hMem); }
                    CloseClipboard();
                    SetStatus(L"Output copied to clipboard.");
                }
                return 0;
            }
        }
        break;
    case WM_SIZE: {
        if (!ctx) break;
        RECT rc; GetClientRect(hwnd, &rc);
        int w = rc.right, h = rc.bottom;
        int pad = 10, btnW = 90;
        int contentW = w - pad * 2 - btnW - 20;
        int halfH = (h - 80) / 2;
        if (ctx->hInput) MoveWindow(ctx->hInput, pad, 58, contentW, halfH, TRUE);
        if (ctx->hEncodeBtn) MoveWindow(ctx->hEncodeBtn, contentW + pad + 15, 58, btnW, 30, TRUE);
        if (ctx->hDecodeBtn) MoveWindow(ctx->hDecodeBtn, contentW + pad + 15, 95, btnW, 30, TRUE);
        if (ctx->hSwapBtn) MoveWindow(ctx->hSwapBtn, contentW + pad + 15, 132, btnW, 22, TRUE);
        if (ctx->hCopyBtn) MoveWindow(ctx->hCopyBtn, contentW + pad + 15, 158, btnW, 22, TRUE);
        int outY = 58 + halfH + 28;
        if (ctx->hOutput) MoveWindow(ctx->hOutput, pad, outY, contentW, h - outY - pad, TRUE);
        break;
    }
    case WM_CLOSE:
        DestroyWindow(hwnd);
        return 0;
    }
    return DefWindowProcW(hwnd, msg, wParam, lParam);
}

void OpenEncodingDialog(HWND parent) {
    EncDlgCtx ctx = {};
    if (!encDlgClassRegistered) {
        WNDCLASSEXW wc = {};
        wc.cbSize = sizeof(wc);
        wc.lpfnWndProc = EncDlgProc;
        wc.hInstance = g_hInstance;
        wc.hCursor = LoadCursor(NULL, IDC_ARROW);
        wc.hbrBackground = (HBRUSH)(COLOR_BTNFACE + 1);
        wc.lpszClassName = ENC_DLG_CLASS;
        RegisterClassExW(&wc);
        encDlgClassRegistered = true;
    }
    int screenW = GetSystemMetrics(SM_CXSCREEN);
    int screenH = GetSystemMetrics(SM_CYSCREEN);
    int dlgW = 850, dlgH = 500;
    HWND hDlg = CreateWindowExW(WS_EX_OVERLAPPEDWINDOW,
        ENC_DLG_CLASS, L"Encoding / Decoding",
        WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX | WS_THICKFRAME | WS_MAXIMIZEBOX,
        (screenW - dlgW) / 2, (screenH - dlgH) / 2, dlgW, dlgH,
        parent, NULL, g_hInstance, &ctx);
    if (!hDlg) return;
    EnableWindow(parent, FALSE);
    ShowWindow(hDlg, SW_SHOW);
    UpdateWindow(hDlg);
    MSG msg;
    while (IsWindow(hDlg)) {
        BOOL ret = GetMessageW(&msg, NULL, 0, 0);
        if (ret == 0 || ret == -1) break;
        if (!IsWindow(hDlg)) break;
        if (!IsDialogMessageW(hDlg, &msg)) { TranslateMessage(&msg); DispatchMessageW(&msg); }
    }
    EnableWindow(parent, TRUE);
    SetForegroundWindow(parent);
}

// ===== KEY GENERATION DIALOG =====
struct KeyGenParams { int value1; int value2; bool confirmed; };
struct KeyGenDialogDef {
    const wchar_t* title; const wchar_t* info;
    const wchar_t* label1; const wchar_t* items1; int defaultIndex1;
    const wchar_t* label2; const wchar_t* items2; int defaultIndex2;
};
struct KeyGenDlgCtx { const KeyGenDialogDef* def; KeyGenParams* params; HWND hCombo1; HWND hCombo2; };

static const wchar_t KEYGEN_DLG_CLASS[] = L"KeyGenDlgClass";
static bool keygenDlgClassRegistered = false;

LRESULT CALLBACK KeyGenDlgProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
    KeyGenDlgCtx* ctx = NULL;
    if (msg == WM_NCCREATE) {
        ctx = (KeyGenDlgCtx*)((CREATESTRUCTW*)lParam)->lpCreateParams;
        SetWindowLongPtr(hwnd, GWLP_USERDATA, (LONG_PTR)ctx);
        return DefWindowProcW(hwnd, msg, wParam, lParam);
    }
    ctx = (KeyGenDlgCtx*)GetWindowLongPtr(hwnd, GWLP_USERDATA);
    if (!ctx) return DefWindowProcW(hwnd, msg, wParam, lParam);

    switch (msg) {
    case WM_CREATE: {
        HFONT hf = hBoldFont ? hBoldFont : (HFONT)GetStockObject(DEFAULT_GUI_FONT);
        const KeyGenDialogDef* d = ctx->def;

        CreateWindowW(L"STATIC", d->info, WS_CHILD | WS_VISIBLE | SS_LEFT,
            12, 10, 296, 48, hwnd, NULL, NULL, NULL);
        CreateWindowW(L"STATIC", d->label1, WS_CHILD | WS_VISIBLE | SS_LEFT,
            12, 65, 80, 20, hwnd, NULL, NULL, NULL);

        ctx->hCombo1 = CreateWindowExW(0, L"COMBOBOX", L"",
            WS_CHILD | WS_VISIBLE | WS_BORDER | CBS_DROPDOWNLIST | WS_VSCROLL,
            100, 62, 200, 150, hwnd, (HMENU)(INT_PTR)IDC_COMBO_PARAM, NULL, NULL);
        SendMessage(ctx->hCombo1, WM_SETFONT, (WPARAM)hf, TRUE);
        const wchar_t* p = d->items1;
        while (*p) { SendMessageW(ctx->hCombo1, CB_ADDSTRING, 0, (LPARAM)p); p += wcslen(p) + 1; }
        SendMessageW(ctx->hCombo1, CB_SETCURSEL, d->defaultIndex1, 0);

        if (d->label2) {
            CreateWindowW(L"STATIC", d->label2, WS_CHILD | WS_VISIBLE | SS_LEFT,
                12, 95, 80, 20, hwnd, NULL, NULL, NULL);
            ctx->hCombo2 = CreateWindowExW(0, L"COMBOBOX", L"",
                WS_CHILD | WS_VISIBLE | WS_BORDER | CBS_DROPDOWNLIST | WS_VSCROLL,
                100, 92, 200, 150, hwnd, (HMENU)(INT_PTR)IDC_COMBO_PARAM2, NULL, NULL);
            SendMessage(ctx->hCombo2, WM_SETFONT, (WPARAM)hf, TRUE);
            const wchar_t* p2 = d->items2;
            while (*p2) { SendMessageW(ctx->hCombo2, CB_ADDSTRING, 0, (LPARAM)p2); p2 += wcslen(p2) + 1; }
            SendMessageW(ctx->hCombo2, CB_SETCURSEL, d->defaultIndex2, 0);
        } else { ctx->hCombo2 = NULL; }

        HWND hBtnOk = CreateWindowW(L"BUTTON", L"Generate", WS_CHILD | WS_VISIBLE | BS_DEFPUSHBUTTON,
            60, 130, 90, 28, hwnd, (HMENU)(INT_PTR)IDC_BTN_GENERATE, NULL, NULL);
        SendMessage(hBtnOk, WM_SETFONT, (WPARAM)hf, TRUE);
        HWND hBtnCancel = CreateWindowW(L"BUTTON", L"Cancel", WS_CHILD | WS_VISIBLE,
            170, 130, 90, 28, hwnd, (HMENU)(INT_PTR)IDC_BTN_CANCEL, NULL, NULL);
        SendMessage(hBtnCancel, WM_SETFONT, (WPARAM)hf, TRUE);
        return 0;
    }
    case WM_COMMAND:
        if (LOWORD(wParam) == IDC_BTN_GENERATE && ctx) {
            ctx->params->value1 = (int)SendMessageW(ctx->hCombo1, CB_GETCURSEL, 0, 0);
            ctx->params->value2 = ctx->hCombo2 ? (int)SendMessageW(ctx->hCombo2, CB_GETCURSEL, 0, 0) : 0;
            ctx->params->confirmed = true;
            DestroyWindow(hwnd);
            return 0;
        }
        if (LOWORD(wParam) == IDC_BTN_CANCEL || LOWORD(wParam) == IDCANCEL) {
            DestroyWindow(hwnd); return 0;
        }
        break;
    case WM_CLOSE: DestroyWindow(hwnd); return 0;
    }
    return DefWindowProcW(hwnd, msg, wParam, lParam);
}

int ShowKeyGenDialog(HWND parent, const KeyGenDialogDef& def, int* outVal1, int* outVal2) {
    KeyGenParams params = { def.defaultIndex1, def.defaultIndex2, false };
    KeyGenDlgCtx ctx = { &def, &params, NULL, NULL };

    if (!keygenDlgClassRegistered) {
        WNDCLASSEXW wc = {};
        wc.cbSize = sizeof(wc);
        wc.lpfnWndProc = KeyGenDlgProc;
        wc.hInstance = g_hInstance;
        wc.hCursor = LoadCursor(NULL, IDC_ARROW);
        wc.hbrBackground = (HBRUSH)(COLOR_BTNFACE + 1);
        wc.lpszClassName = KEYGEN_DLG_CLASS;
        RegisterClassExW(&wc);
        keygenDlgClassRegistered = true;
    }
    int screenW = GetSystemMetrics(SM_CXSCREEN);
    int screenH = GetSystemMetrics(SM_CYSCREEN);
    HWND hDlg = CreateWindowExW(WS_EX_DLGMODALFRAME | WS_EX_TOPMOST,
        KEYGEN_DLG_CLASS, def.title,
        WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU | WS_THICKFRAME | WS_MAXIMIZEBOX,
        (screenW - 420) / 2, (screenH - 230) / 2, 420, 230,
        parent, NULL, g_hInstance, &ctx);
    if (!hDlg) return 0;

    EnableWindow(parent, FALSE);
    ShowWindow(hDlg, SW_SHOW);
    MSG msg;
    while (IsWindow(hDlg)) {
        BOOL ret = GetMessageW(&msg, NULL, 0, 0);
        if (ret == 0 || ret == -1) break;
        if (!IsWindow(hDlg)) break;
        if (!IsDialogMessageW(hDlg, &msg)) { TranslateMessage(&msg); DispatchMessageW(&msg); }
    }
    EnableWindow(parent, TRUE);
    SetForegroundWindow(parent);

    if (params.confirmed) { if (outVal1) *outVal1 = params.value1; if (outVal2) *outVal2 = params.value2; return 1; }
    return 0;
}

// ===================================================================
//  KEY GENERATION — Windows CNG (BCrypt / NCrypt)
// ===================================================================

static const wchar_t* EccCurveName(int bits) {
    switch (bits) {
        case 256: return BCRYPT_ECC_CURVE_NISTP256;
        case 384: return BCRYPT_ECC_CURVE_NISTP384;
        case 521: return BCRYPT_ECC_CURVE_NISTP521;
        default:  return BCRYPT_ECC_CURVE_NISTP256;
    }
}

static std::string FormatKeyOutput(const std::string& title, const std::string& pemPriv,
    const std::string& pemPub, const std::vector<unsigned char>& derPriv,
    const std::vector<unsigned char>& derPub) {
    std::ostringstream oss;
    oss << "=== " << title << " ===\r\n\r\n";
    if (!pemPriv.empty()) oss << "--- PEM Private Key ---\r\n" << pemPriv << "\r\n\r\n";
    if (!pemPub.empty()) oss << "--- PEM Public Key ---\r\n" << pemPub << "\r\n\r\n";
    if (!derPriv.empty()) {
        oss << "--- DER (Base64) Private ---\r\n" << WrapLines(BytesToBase64(derPriv.data(), derPriv.size()), 64) << "\r\n\r\n";
        oss << "--- Hex Private (" << derPriv.size() << " bytes) ---\r\n" << WrapLines(BytesToHex(derPriv.data(), derPriv.size()), 64) << "\r\n\r\n";
    }
    if (!derPub.empty()) {
        oss << "--- DER (Base64) Public ---\r\n" << WrapLines(BytesToBase64(derPub.data(), derPub.size()), 64) << "\r\n\r\n";
        oss << "--- Hex Public (" << derPub.size() << " bytes) ---\r\n" << WrapLines(BytesToHex(derPub.data(), derPub.size()), 64) << "\r\n";
    }
    return oss.str();
}

static std::string FormatSymmetricKeyOutput(const std::string& title, const std::vector<unsigned char>& key) {
    std::ostringstream oss;
    oss << "=== " << title << " ===\r\n\r\n";
    oss << "--- Raw Hex (" << key.size() * 8 << " bits) ---\r\n" << WrapLines(BytesToHex(key.data(), key.size()), 64) << "\r\n\r\n";
    oss << "--- Base64 ---\r\n" << WrapLines(BytesToBase64(key.data(), key.size()), 64) << "\r\n\r\n";
    oss << "--- C Array ---\r\nunsigned char key[" << key.size() << "] = {";
    for (size_t i = 0; i < key.size(); i++) {
        if (i % 16 == 0) oss << "\r\n    ";
        oss << "0x" << std::hex << std::setw(2) << std::setfill('0') << (int)key[i];
        if (i + 1 < key.size()) oss << ", ";
    }
    oss << "\r\n};\r\n";
    return oss.str();
}

void GenerateRSAKeyPair(HWND, int bits) {
    NCRYPT_PROV_HANDLE hProv = 0; NCRYPT_KEY_HANDLE hKey = 0; NTSTATUS st;
    st = NCryptOpenStorageProvider(&hProv, MS_KEY_STORAGE_PROVIDER, 0);
    if (!NT_SUCCESS(st)) { SetStatus(L"RSA: Open provider failed. " + std::to_wstring(st)); return; }
    st = NCryptCreatePersistedKey(hProv, &hKey, BCRYPT_RSA_ALGORITHM, NULL, 0, 0);
    if (!NT_SUCCESS(st)) { NCryptFreeObject(hProv); SetStatus(L"RSA: Create key failed. " + std::to_wstring(st)); return; }
    st = NCryptSetProperty(hKey, NCRYPT_LENGTH_PROPERTY, (PBYTE)&bits, sizeof(bits), 0);
    if (!NT_SUCCESS(st)) { NCryptFreeObject(hKey); NCryptFreeObject(hProv); SetStatus(L"RSA: Set length failed. " + std::to_wstring(st)); return; }
    DWORD ep = NCRYPT_ALLOW_PLAINTEXT_EXPORT_FLAG | NCRYPT_ALLOW_EXPORT_FLAG;
    NCryptSetProperty(hKey, NCRYPT_EXPORT_POLICY_PROPERTY, (PBYTE)&ep, sizeof(ep), 0);
    st = NCryptFinalizeKey(hKey, 0);
    if (!NT_SUCCESS(st)) { NCryptFreeObject(hKey); NCryptFreeObject(hProv); SetStatus(L"RSA: Finalize failed. " + std::to_wstring(st)); return; }

    DWORD cb = 0;
    NCryptExportKey(hKey, 0, BCRYPT_PRIVATE_KEY_BLOB, NULL, NULL, 0, &cb, 0);
    std::vector<unsigned char> priv(cb); NCryptExportKey(hKey, 0, BCRYPT_PRIVATE_KEY_BLOB, NULL, priv.data(), cb, &cb, 0);
    cb = 0; NCryptExportKey(hKey, 0, BCRYPT_PUBLIC_KEY_BLOB, NULL, NULL, 0, &cb, 0);
    std::vector<unsigned char> pub(cb); NCryptExportKey(hKey, 0, BCRYPT_PUBLIC_KEY_BLOB, NULL, pub.data(), cb, &cb, 0);

    std::string output = FormatKeyOutput("RSA Key Pair (" + std::to_string(bits) + "-bit)",
        WrapPem(BytesToBase64(priv.data(), priv.size()), "RSA PRIVATE KEY"),
        WrapPem(BytesToBase64(pub.data(), pub.size()), "PUBLIC KEY"), priv, pub);
    SetEditText(hOutputEdit, Utf8ToWstring(output));
    SetStatus(L"RSA " + std::to_wstring(bits) + L"-bit key pair generated.");
    NCryptFreeObject(hKey); NCryptFreeObject(hProv);
}

void GenerateECCKeyPair(HWND, const wchar_t* algorithm, const wchar_t* curveName, int bits) {
    NCRYPT_PROV_HANDLE hProv = 0; NCRYPT_KEY_HANDLE hKey = 0; NTSTATUS st;
    st = NCryptOpenStorageProvider(&hProv, MS_KEY_STORAGE_PROVIDER, 0);
    if (!NT_SUCCESS(st)) { SetStatus(L"ECC: Open provider failed. " + std::to_wstring(st)); return; }
    st = NCryptCreatePersistedKey(hProv, &hKey, algorithm, NULL, 0, 0);
    if (!NT_SUCCESS(st)) { NCryptFreeObject(hProv); SetStatus(L"ECC: Create key failed. " + std::to_wstring(st)); return; }
    st = NCryptSetProperty(hKey, NCRYPT_ECC_CURVE_NAME_PROPERTY, (PBYTE)curveName,
        (DWORD)((wcslen(curveName) + 1) * sizeof(wchar_t)), 0);
    if (!NT_SUCCESS(st)) { NCryptFreeObject(hKey); NCryptFreeObject(hProv); SetStatus(L"ECC: Set curve failed. " + std::to_wstring(st)); return; }
    DWORD ep = NCRYPT_ALLOW_PLAINTEXT_EXPORT_FLAG | NCRYPT_ALLOW_EXPORT_FLAG;
    NCryptSetProperty(hKey, NCRYPT_EXPORT_POLICY_PROPERTY, (PBYTE)&ep, sizeof(ep), 0);
    st = NCryptFinalizeKey(hKey, 0);
    if (!NT_SUCCESS(st)) { NCryptFreeObject(hKey); NCryptFreeObject(hProv); SetStatus(L"ECC: Finalize failed. " + std::to_wstring(st)); return; }

    DWORD cb = 0;
    NCryptExportKey(hKey, 0, BCRYPT_PRIVATE_KEY_BLOB, NULL, NULL, 0, &cb, 0);
    std::vector<unsigned char> priv(cb); NCryptExportKey(hKey, 0, BCRYPT_PRIVATE_KEY_BLOB, NULL, priv.data(), cb, &cb, 0);
    cb = 0; NCryptExportKey(hKey, 0, BCRYPT_PUBLIC_KEY_BLOB, NULL, NULL, 0, &cb, 0);
    std::vector<unsigned char> pub(cb); NCryptExportKey(hKey, 0, BCRYPT_PUBLIC_KEY_BLOB, NULL, pub.data(), cb, &cb, 0);

    std::string algoName = (wcscmp(algorithm, BCRYPT_ECDSA_ALGORITHM) == 0) ? "ECDSA" : "ECDH";
    std::string output = FormatKeyOutput(algoName + " Key Pair (" + std::to_string(bits) + "-bit)",
        WrapPem(BytesToBase64(priv.data(), priv.size()), "EC PRIVATE KEY"),
        WrapPem(BytesToBase64(pub.data(), pub.size()), "PUBLIC KEY"), priv, pub);
    SetEditText(hOutputEdit, Utf8ToWstring(output));
    SetStatus(Utf8ToWstring(algoName) + L" key pair generated.");
    NCryptFreeObject(hKey); NCryptFreeObject(hProv);
}

void GenerateDSAKeyPair(HWND, int bits) {
    NCRYPT_PROV_HANDLE hProv = 0; NCRYPT_KEY_HANDLE hKey = 0; NTSTATUS st;
    st = NCryptOpenStorageProvider(&hProv, MS_KEY_STORAGE_PROVIDER, 0);
    if (!NT_SUCCESS(st)) { SetStatus(L"DSA: Open provider failed. " + std::to_wstring(st)); return; }
    st = NCryptCreatePersistedKey(hProv, &hKey, BCRYPT_DSA_ALGORITHM, NULL, 0, 0);
    if (!NT_SUCCESS(st)) { NCryptFreeObject(hProv); SetStatus(L"DSA: Create key failed. " + std::to_wstring(st)); return; }
    NCryptSetProperty(hKey, NCRYPT_LENGTH_PROPERTY, (PBYTE)&bits, sizeof(bits), 0);
    DWORD ep = NCRYPT_ALLOW_PLAINTEXT_EXPORT_FLAG | NCRYPT_ALLOW_EXPORT_FLAG;
    NCryptSetProperty(hKey, NCRYPT_EXPORT_POLICY_PROPERTY, (PBYTE)&ep, sizeof(ep), 0);
    st = NCryptFinalizeKey(hKey, 0);
    if (!NT_SUCCESS(st)) { NCryptFreeObject(hKey); NCryptFreeObject(hProv); SetStatus(L"DSA: Finalize failed. " + std::to_wstring(st)); return; }

    DWORD cb = 0;
    NCryptExportKey(hKey, 0, BCRYPT_PRIVATE_KEY_BLOB, NULL, NULL, 0, &cb, 0);
    std::vector<unsigned char> priv(cb); NCryptExportKey(hKey, 0, BCRYPT_PRIVATE_KEY_BLOB, NULL, priv.data(), cb, &cb, 0);
    cb = 0; NCryptExportKey(hKey, 0, BCRYPT_PUBLIC_KEY_BLOB, NULL, NULL, 0, &cb, 0);
    std::vector<unsigned char> pub(cb); NCryptExportKey(hKey, 0, BCRYPT_PUBLIC_KEY_BLOB, NULL, pub.data(), cb, &cb, 0);

    std::string output = FormatKeyOutput("DSA Key Pair (" + std::to_string(bits) + "-bit)",
        WrapPem(BytesToBase64(priv.data(), priv.size()), "DSA PRIVATE KEY"),
        WrapPem(BytesToBase64(pub.data(), pub.size()), "PUBLIC KEY"), priv, pub);
    SetEditText(hOutputEdit, Utf8ToWstring(output));
    SetStatus(L"DSA " + std::to_wstring(bits) + L"-bit key pair generated.");
    NCryptFreeObject(hKey); NCryptFreeObject(hProv);
}

void GenerateDHKeyPair(HWND, int bits) {
    NCRYPT_PROV_HANDLE hProv = 0; NCRYPT_KEY_HANDLE hKey = 0; NTSTATUS st;
    st = NCryptOpenStorageProvider(&hProv, MS_KEY_STORAGE_PROVIDER, 0);
    if (!NT_SUCCESS(st)) { SetStatus(L"DH: Open provider failed. " + std::to_wstring(st)); return; }
    st = NCryptCreatePersistedKey(hProv, &hKey, BCRYPT_DH_ALGORITHM, NULL, 0, 0);
    if (!NT_SUCCESS(st)) { NCryptFreeObject(hProv); SetStatus(L"DH: Create key failed. " + std::to_wstring(st)); return; }
    NCryptSetProperty(hKey, NCRYPT_LENGTH_PROPERTY, (PBYTE)&bits, sizeof(bits), 0);
    DWORD ep = NCRYPT_ALLOW_PLAINTEXT_EXPORT_FLAG | NCRYPT_ALLOW_EXPORT_FLAG;
    NCryptSetProperty(hKey, NCRYPT_EXPORT_POLICY_PROPERTY, (PBYTE)&ep, sizeof(ep), 0);
    st = NCryptFinalizeKey(hKey, 0);
    if (!NT_SUCCESS(st)) { NCryptFreeObject(hKey); NCryptFreeObject(hProv); SetStatus(L"DH: Finalize failed. " + std::to_wstring(st)); return; }

    DWORD cb = 0;
    NCryptExportKey(hKey, 0, BCRYPT_PRIVATE_KEY_BLOB, NULL, NULL, 0, &cb, 0);
    std::vector<unsigned char> priv(cb); NCryptExportKey(hKey, 0, BCRYPT_PRIVATE_KEY_BLOB, NULL, priv.data(), cb, &cb, 0);
    cb = 0; NCryptExportKey(hKey, 0, BCRYPT_PUBLIC_KEY_BLOB, NULL, NULL, 0, &cb, 0);
    std::vector<unsigned char> pub(cb); NCryptExportKey(hKey, 0, BCRYPT_PUBLIC_KEY_BLOB, NULL, pub.data(), cb, &cb, 0);

    std::string output = FormatKeyOutput("DH Key Pair (" + std::to_string(bits) + "-bit)",
        WrapPem(BytesToBase64(priv.data(), priv.size()), "DH PRIVATE KEY"),
        WrapPem(BytesToBase64(pub.data(), pub.size()), "DH PUBLIC KEY"), priv, pub);
    SetEditText(hOutputEdit, Utf8ToWstring(output));
    SetStatus(L"DH " + std::to_wstring(bits) + L"-bit key pair generated.");
    NCryptFreeObject(hKey); NCryptFreeObject(hProv);
}

void GenerateSymmetricKey(HWND, const wchar_t*, int bits, const std::string& title) {
    std::vector<unsigned char> key(bits / 8);
    NTSTATUS st = BCryptGenRandom(NULL, key.data(), (ULONG)key.size(), BCRYPT_USE_SYSTEM_PREFERRED_RNG);
    if (!NT_SUCCESS(st)) { SetStatus(Utf8ToWstring(title) + L": RNG failed. " + std::to_wstring(st)); return; }
    SetEditText(hOutputEdit, Utf8ToWstring(FormatSymmetricKeyOutput(title, key)));
    SetStatus(Utf8ToWstring(title) + L" generated.");
}

void GenerateRandomBytes(HWND, int count) {
    std::vector<unsigned char> bytes(count);
    NTSTATUS st = BCryptGenRandom(NULL, bytes.data(), (ULONG)count, BCRYPT_USE_SYSTEM_PREFERRED_RNG);
    if (!NT_SUCCESS(st)) { SetStatus(L"Random: RNG failed. " + std::to_wstring(st)); return; }
    std::ostringstream oss;
    oss << "=== Random Bytes (" << count << " bytes) ===\r\n\r\n";
    oss << "--- Hex ---\r\n" << WrapLines(BytesToHex(bytes.data(), bytes.size()), 64) << "\r\n\r\n";
    oss << "--- Base64 ---\r\n" << WrapLines(BytesToBase64(bytes.data(), bytes.size()), 64) << "\r\n\r\n";
    oss << "--- C Array ---\r\nunsigned char data[" << count << "] = {";
    for (int i = 0; i < count; i++) {
        if (i % 16 == 0) oss << "\r\n    ";
        oss << "0x" << std::hex << std::setw(2) << std::setfill('0') << (int)bytes[i];
        if (i + 1 < count) oss << ", ";
    }
    oss << "\r\n};\r\n";
    SetEditText(hOutputEdit, Utf8ToWstring(oss.str()));
    SetStatus(L"Generated " + std::to_wstring(count) + L" random bytes.");
}

// ===== KEY GEN MENU HANDLERS =====
void HandleKeyGenRSA(HWND hwnd) {
    static const wchar_t items[] = L"1024\0" L"2048 (Recommended)\0" L"3072\0" L"4096\0";
    static const int sizes[] = { 1024, 2048, 3072, 4096 };
    KeyGenDialogDef def = { L"Generate RSA Key Pair",
        L"Select RSA key size in bits:\nLarger = more secure, slower.",
        L"Key Size:", items, 1, NULL, NULL, 0 };
    int idx = 0;
    if (ShowKeyGenDialog(hwnd, def, &idx, NULL)) GenerateRSAKeyPair(hwnd, sizes[idx]);
}

void HandleKeyGenECC(HWND hwnd, const wchar_t* algo, const std::string& name) {
    static const wchar_t items[] = L"P-256 (Recommended)\0" L"P-384\0" L"P-521\0";
    static const int bits[] = { 256, 384, 521 };
    std::wstring t = L"Generate " + Utf8ToWstring(name) + L" Key Pair";
    std::wstring i = L"Select elliptic curve for " + Utf8ToWstring(name) + L":";
    KeyGenDialogDef def = { t.c_str(), i.c_str(), L"Curve:", items, 0, NULL, NULL, 0 };
    int idx = 0;
    if (ShowKeyGenDialog(hwnd, def, &idx, NULL)) GenerateECCKeyPair(hwnd, algo, EccCurveName(bits[idx]), bits[idx]);
}

void HandleKeyGenDSA(HWND hwnd) {
    static const wchar_t items[] = L"1024\0" L"2048 (Recommended)\0";
    static const int sizes[] = { 1024, 2048 };
    KeyGenDialogDef def = { L"Generate DSA Key Pair", L"Select DSA key size in bits:",
        L"Key Size:", items, 1, NULL, NULL, 0 };
    int idx = 0;
    if (ShowKeyGenDialog(hwnd, def, &idx, NULL)) GenerateDSAKeyPair(hwnd, sizes[idx]);
}

void HandleKeyGenDH(HWND hwnd) {
    static const wchar_t items[] = L"1024\0" L"2048 (Recommended)\0";
    static const int sizes[] = { 1024, 2048 };
    KeyGenDialogDef def = { L"Generate DH Key Pair", L"Select DH key size in bits:",
        L"Key Size:", items, 1, NULL, NULL, 0 };
    int idx = 0;
    if (ShowKeyGenDialog(hwnd, def, &idx, NULL)) GenerateDHKeyPair(hwnd, sizes[idx]);
}

void HandleKeyGenAES(HWND hwnd) {
    static const wchar_t items[] = L"128\0" L"192\0" L"256 (Recommended)\0";
    static const int sizes[] = { 128, 192, 256 };
    KeyGenDialogDef def = { L"Generate AES Key", L"Select AES key size in bits:",
        L"Key Size:", items, 2, NULL, NULL, 0 };
    int idx = 0;
    if (ShowKeyGenDialog(hwnd, def, &idx, NULL))
        GenerateSymmetricKey(hwnd, NULL, sizes[idx], "AES-" + std::to_string(sizes[idx]) + " Key");
}

void HandleKeyGen3DES(HWND hwnd) {
    static const wchar_t items[] = L"128\0" L"192 (Recommended)\0";
    static const int sizes[] = { 128, 192 };
    KeyGenDialogDef def = { L"Generate 3DES Key", L"Select 3DES key size in bits:",
        L"Key Size:", items, 1, NULL, NULL, 0 };
    int idx = 0;
    if (ShowKeyGenDialog(hwnd, def, &idx, NULL))
        GenerateSymmetricKey(hwnd, NULL, sizes[idx], "3DES-" + std::to_string(sizes[idx]) + " Key");
}

void HandleKeyGenChaCha20(HWND hwnd) {
    GenerateSymmetricKey(hwnd, NULL, 256, "ChaCha20-Poly1305 Key (256-bit)");
}

void HandleKeyGenRandom(HWND hwnd) {
    static const wchar_t items[] = L"16 bytes\0" L"32 bytes (Recommended)\0" L"64 bytes\0" L"128 bytes\0" L"256 bytes\0";
    static const int counts[] = { 16, 32, 64, 128, 256 };
    KeyGenDialogDef def = { L"Generate Random Bytes", L"Select number of random bytes:",
        L"Byte Count:", items, 1, NULL, NULL, 0 };
    int idx = 0;
    if (ShowKeyGenDialog(hwnd, def, &idx, NULL)) GenerateRandomBytes(hwnd, counts[idx]);
}

// ===== CSR (Certificate Signing Request) Generation =====

struct DerBuilder {
    std::vector<unsigned char> buf;
    void putByte(unsigned char b) { buf.push_back(b); }
    void putBytes(const unsigned char* p, size_t n) { buf.insert(buf.end(), p, p + n); }
    void putLength(size_t len) {
        if (len < 0x80) { putByte((unsigned char)len); }
        else if (len < 0x100) { putByte(0x81); putByte((unsigned char)len); }
        else { putByte(0x82); putByte((unsigned char)(len >> 8)); putByte((unsigned char)len); }
    }
    std::vector<unsigned char> wrapTag(unsigned char tag) {
        std::vector<unsigned char> r = { tag };
        putLength(buf.size());
        r.insert(r.end(), buf.begin(), buf.end());
        return r;
    }
    void encodeLength(size_t len, std::vector<unsigned char>& out) {
        if (len < 0x80) { out.push_back((unsigned char)len); }
        else if (len < 0x100) { out.push_back(0x81); out.push_back((unsigned char)len); }
        else { out.push_back(0x82); out.push_back((unsigned char)(len >> 8)); out.push_back((unsigned char)len); }
    }
};

static std::vector<unsigned char> DerEncodeLength(size_t len) {
    std::vector<unsigned char> r;
    if (len < 0x80) { r.push_back((unsigned char)len); }
    else if (len < 0x100) { r.push_back(0x81); r.push_back((unsigned char)len); }
    else { r.push_back(0x82); r.push_back((unsigned char)(len >> 8)); r.push_back((unsigned char)len); }
    return r;
}

static std::vector<unsigned char> DerWrap(unsigned char tag, const std::vector<unsigned char>& content) {
    std::vector<unsigned char> r = { tag };
    auto len = DerEncodeLength(content.size());
    r.insert(r.end(), len.begin(), len.end());
    r.insert(r.end(), content.begin(), content.end());
    return r;
}

static std::vector<unsigned char> DerInteger(const std::vector<unsigned char>& val) {
    std::vector<unsigned char> content;
    if (!val.empty() && (val[0] & 0x80)) { content.push_back(0x00); }
    content.insert(content.end(), val.begin(), val.end());
    return DerWrap(0x02, content);
}

static std::vector<unsigned char> DerIntegerFromSize(DWORD val) {
    std::vector<unsigned char> bytes;
    bool started = false;
    for (int i = 3; i >= 0; i--) {
        unsigned char b = (unsigned char)((val >> (i * 8)) & 0xFF);
        if (b || started || i == 0) { bytes.push_back(b); started = true; }
    }
    return DerInteger(bytes);
}

static std::vector<unsigned char> DerOid(const unsigned char* oid, size_t len) {
    return DerWrap(0x06, std::vector<unsigned char>(oid, oid + len));
}

static std::vector<unsigned char> DerBitString(const std::vector<unsigned char>& data) {
    std::vector<unsigned char> content;
    content.push_back(0x00);
    content.insert(content.end(), data.begin(), data.end());
    return DerWrap(0x03, content);
}

static std::vector<unsigned char> DerUtf8String(const std::string& s) {
    return DerWrap(0x0C, std::vector<unsigned char>(s.begin(), s.end()));
}

static std::vector<unsigned char> DerSequence(const std::vector<std::vector<unsigned char>>& items) {
    std::vector<unsigned char> content;
    for (auto& item : items) content.insert(content.end(), item.begin(), item.end());
    return DerWrap(0x30, content);
}

static std::vector<unsigned char> DerSet(const std::vector<unsigned char>& content) {
    return DerWrap(0x31, content);
}

struct CSRDlgCtx {
    HWND hCN, hOrg, hOU, hLoc, hState, hCountry, hEmail;
    HWND hKeyCombo;
    bool confirmed;
    std::wstring cn, org, ou, loc, state, country, email;
    int keyIdx;
};

static const wchar_t CSR_DLG_CLASS[] = L"CSRDialogClass";
static bool csrDlgClassRegistered = false;

LRESULT CALLBACK CSRDlgProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
    CSRDlgCtx* ctx = NULL;
    if (msg == WM_NCCREATE) {
        ctx = (CSRDlgCtx*)((CREATESTRUCTW*)lParam)->lpCreateParams;
        SetWindowLongPtr(hwnd, GWLP_USERDATA, (LONG_PTR)ctx);
        return DefWindowProcW(hwnd, msg, wParam, lParam);
    }
    ctx = (CSRDlgCtx*)GetWindowLongPtr(hwnd, GWLP_USERDATA);
    if (!ctx) return DefWindowProcW(hwnd, msg, wParam, lParam);

    switch (msg) {
    case WM_CREATE: {
        HFONT hf = hBoldFont ? hBoldFont : (HFONT)GetStockObject(DEFAULT_GUI_FONT);
        HFONT hnf = hFont ? hFont : (HFONT)GetStockObject(SYSTEM_FONT);
        int x = 12, lw = 110, ew = 380, ex = x + lw + 8, y = 10;

        auto MakeLabel = [&](const wchar_t* text, int cy) {
            HWND h = CreateWindowW(L"STATIC", text, WS_CHILD | WS_VISIBLE | SS_RIGHT,
                x, cy + 3, lw, 20, hwnd, NULL, NULL, NULL);
            SendMessage(h, WM_SETFONT, (WPARAM)hf, TRUE);
        };
        auto MakeEdit = [&](int ctrlId, int cy) {
            HWND h = CreateWindowExW(WS_EX_CLIENTEDGE, L"EDIT", L"",
                WS_CHILD | WS_VISIBLE | WS_TABSTOP | ES_AUTOHSCROLL,
                ex, cy, ew, 23, hwnd, (HMENU)(INT_PTR)ctrlId, NULL, NULL);
            SendMessage(h, WM_SETFONT, (WPARAM)hnf, TRUE);
            return h;
        };

        MakeLabel(L"Common Name (CN):", y);
        ctx->hCN = MakeEdit(IDC_CSR_CN, y);
        y += 30;
        MakeLabel(L"Organization (O):", y);
        ctx->hOrg = MakeEdit(IDC_CSR_ORG, y);
        y += 30;
        MakeLabel(L"Org Unit (OU):", y);
        ctx->hOU = MakeEdit(IDC_CSR_OU, y);
        y += 30;
        MakeLabel(L"Locality (L):", y);
        ctx->hLoc = MakeEdit(IDC_CSR_LOCALITY, y);
        y += 30;
        MakeLabel(L"State (S):", y);
        ctx->hState = MakeEdit(IDC_CSR_STATE, y);
        y += 30;
        MakeLabel(L"Country (C):", y);
        ctx->hCountry = MakeEdit(IDC_CSR_COUNTRY, y);
        y += 30;
        MakeLabel(L"Email (E):", y);
        ctx->hEmail = MakeEdit(IDC_CSR_EMAIL, y);

        y += 35;
        HWND hLabel = CreateWindowW(L"STATIC", L"Key Type:",
            WS_CHILD | WS_VISIBLE | SS_RIGHT,
            x, y + 3, lw, 20, hwnd, NULL, NULL, NULL);
        SendMessage(hLabel, WM_SETFONT, (WPARAM)hf, TRUE);

        ctx->hKeyCombo = CreateWindowExW(0, L"COMBOBOX", L"",
            WS_CHILD | WS_VISIBLE | WS_TABSTOP | WS_BORDER | CBS_DROPDOWNLIST | WS_VSCROLL,
            ex, y, ew, 200, hwnd, (HMENU)(INT_PTR)IDC_CSR_KEYTYPE, NULL, NULL);
        SendMessage(ctx->hKeyCombo, WM_SETFONT, (WPARAM)hf, TRUE);
        const wchar_t* keyTypes[] = {
            L"RSA 2048 (Recommended)", L"RSA 3072", L"RSA 4096",
            L"ECDSA P-256", L"ECDSA P-384", L"ECDSA P-521"
        };
        for (auto kt : keyTypes) SendMessageW(ctx->hKeyCombo, CB_ADDSTRING, 0, (LPARAM)kt);
        SendMessageW(ctx->hKeyCombo, CB_SETCURSEL, 0, 0);

        y += 40;
        HWND hGenBtn = CreateWindowW(L"BUTTON", L"Generate CSR",
            WS_CHILD | WS_VISIBLE | WS_TABSTOP | BS_DEFPUSHBUTTON,
            ex, y, 130, 30, hwnd, (HMENU)(INT_PTR)IDC_CSR_GENERATE, NULL, NULL);
        SendMessage(hGenBtn, WM_SETFONT, (WPARAM)hf, TRUE);
        HWND hCancelBtn = CreateWindowW(L"BUTTON", L"Cancel",
            WS_CHILD | WS_VISIBLE | WS_TABSTOP,
            ex + 140, y, 100, 30, hwnd, (HMENU)(INT_PTR)IDC_CSR_CANCEL, NULL, NULL);
        SendMessage(hCancelBtn, WM_SETFONT, (WPARAM)hf, TRUE);

        SetFocus(ctx->hCN);
        return 0;
    }
    case WM_COMMAND:
        if (ctx) {
            if (LOWORD(wParam) == IDC_CSR_GENERATE) {
                ctx->cn = GetEditText(ctx->hCN);
                if (ctx->cn.empty()) { MessageBoxW(hwnd, L"Common Name (CN) is required.", L"CSR", MB_ICONINFORMATION); SetFocus(ctx->hCN); return 0; }
                ctx->org = GetEditText(ctx->hOrg);
                ctx->ou = GetEditText(ctx->hOU);
                ctx->loc = GetEditText(ctx->hLoc);
                ctx->state = GetEditText(ctx->hState);
                ctx->country = GetEditText(ctx->hCountry);
                ctx->email = GetEditText(ctx->hEmail);
                ctx->keyIdx = (int)SendMessageW(ctx->hKeyCombo, CB_GETCURSEL, 0, 0);
                ctx->confirmed = true;
                DestroyWindow(hwnd);
                return 0;
            }
            if (LOWORD(wParam) == IDC_CSR_CANCEL || LOWORD(wParam) == IDCANCEL) { DestroyWindow(hwnd); return 0; }
        }
        break;
    case WM_SIZE: {
        RECT rc; GetClientRect(hwnd, &rc);
        int cw = rc.right, ch = rc.bottom;
        HWND hChild = GetWindow(hwnd, GW_CHILD);
        int bottomY = ch - 40;
        while (hChild) {
            HWND hNext = GetWindow(hChild, GW_HWNDNEXT);
            wchar_t cls[32] = {};
            GetClassNameW(hChild, cls, 32);
            RECT cr = {}; GetWindowRect(hChild, &cr);
            ScreenToClient(hwnd, (POINT*)&cr);
            int origY = cr.top;
            if (wcscmp(cls, L"BUTTON") == 0) {
                MoveWindow(hChild, cr.left, bottomY, cr.right - cr.left, cr.bottom - cr.top, TRUE);
            } else if (wcscmp(cls, L"EDIT") == 0 || wcscmp(cls, L"COMBOBOX") == 0) {
                int newW = cw - cr.left - 12;
                if (newW < 80) newW = 80;
                MoveWindow(hChild, cr.left, origY, newW, cr.bottom - cr.top, TRUE);
            }
            hChild = hNext;
        }
        break;
    }
    case WM_CLOSE: DestroyWindow(hwnd); return 0;
    }
    return DefWindowProcW(hwnd, msg, wParam, lParam);
}

bool OpenCSRDialog(HWND parent, CSRDlgCtx* ctx) {
    if (!csrDlgClassRegistered) {
        WNDCLASSEXW wc = {};
        wc.cbSize = sizeof(wc);
        wc.lpfnWndProc = CSRDlgProc;
        wc.hInstance = g_hInstance;
        wc.hCursor = LoadCursor(NULL, IDC_ARROW);
        wc.hbrBackground = (HBRUSH)(COLOR_BTNFACE + 1);
        wc.lpszClassName = CSR_DLG_CLASS;
        RegisterClassExW(&wc);
        csrDlgClassRegistered = true;
    }
    int screenW = GetSystemMetrics(SM_CXSCREEN);
    int screenH = GetSystemMetrics(SM_CYSCREEN);
    int dlgW = 660, dlgH = 440;
    HWND hDlg = CreateWindowExW(WS_EX_DLGMODALFRAME | WS_EX_TOPMOST,
        CSR_DLG_CLASS, L"Generate Certificate Signing Request",
        WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU | WS_THICKFRAME | WS_MAXIMIZEBOX,
        (screenW - dlgW) / 2, (screenH - dlgH) / 2, dlgW, dlgH,
        parent, NULL, g_hInstance, ctx);
    if (!hDlg) return false;
    EnableWindow(parent, FALSE);
    ShowWindow(hDlg, SW_SHOW);
    MSG msg;
    while (IsWindow(hDlg)) {
        BOOL ret = GetMessageW(&msg, NULL, 0, 0);
        if (ret == 0 || ret == -1) break;
        if (!IsWindow(hDlg)) break;
        if (!IsDialogMessageW(hDlg, &msg)) { TranslateMessage(&msg); DispatchMessageW(&msg); }
    }
    EnableWindow(parent, TRUE);
    SetForegroundWindow(parent);
    return ctx->confirmed;
}

static std::vector<unsigned char> Sha256Hash(const unsigned char* data, size_t len) {
    BCRYPT_ALG_HANDLE hAlg = NULL;
    BCRYPT_HASH_HANDLE hHash = NULL;
    std::vector<unsigned char> hash(32);
    BCryptOpenAlgorithmProvider(&hAlg, BCRYPT_SHA256_ALGORITHM, NULL, 0);
    BCryptCreateHash(hAlg, &hHash, NULL, 0, NULL, 0, 0);
    BCryptHashData(hHash, (PUCHAR)data, (ULONG)len, 0);
    BCryptFinishHash(hHash, hash.data(), 32, 0);
    BCryptDestroyHash(hHash);
    BCryptCloseAlgorithmProvider(hAlg, 0);
    return hash;
}

static bool BuildCSR(
    const std::wstring& cn, const std::wstring& org, const std::wstring& ou,
    const std::wstring& loc, const std::wstring& state, const std::wstring& country,
    const std::wstring& email, int keyIdx, std::string& outCsrPem,
    std::string& outPrivPem, std::string& outPubPem, std::string& outInfo)
{
    const wchar_t* ncryptAlgo = BCRYPT_RSA_ALGORITHM;
    const wchar_t* ecCurve = NULL;
    int rsaBits = 2048;
    bool isECC = false;

    switch (keyIdx) {
    case 0: rsaBits = 2048; break;
    case 1: rsaBits = 3072; break;
    case 2: rsaBits = 4096; break;
    case 3: ncryptAlgo = BCRYPT_ECDSA_ALGORITHM; ecCurve = BCRYPT_ECC_CURVE_NISTP256; isECC = true; break;
    case 4: ncryptAlgo = BCRYPT_ECDSA_ALGORITHM; ecCurve = BCRYPT_ECC_CURVE_NISTP384; isECC = true; break;
    case 5: ncryptAlgo = BCRYPT_ECDSA_ALGORITHM; ecCurve = BCRYPT_ECC_CURVE_NISTP521; isECC = true; break;
    }

    NCRYPT_PROV_HANDLE hProv = 0;
    NCRYPT_KEY_HANDLE hKey = 0;
    NTSTATUS st;

    st = NCryptOpenStorageProvider(&hProv, MS_KEY_STORAGE_PROVIDER, 0);
    if (!NT_SUCCESS(st)) return false;

    st = NCryptCreatePersistedKey(hProv, &hKey, ncryptAlgo, NULL, 0, 0);
    if (!NT_SUCCESS(st)) { NCryptFreeObject(hProv); return false; }

    if (isECC) {
        st = NCryptSetProperty(hKey, NCRYPT_ECC_CURVE_NAME_PROPERTY, (PBYTE)ecCurve,
            (DWORD)((wcslen(ecCurve) + 1) * sizeof(wchar_t)), 0);
    } else {
        st = NCryptSetProperty(hKey, NCRYPT_LENGTH_PROPERTY, (PBYTE)&rsaBits, sizeof(rsaBits), 0);
    }
    if (!NT_SUCCESS(st)) { NCryptFreeObject(hKey); NCryptFreeObject(hProv); return false; }

    DWORD ep = NCRYPT_ALLOW_PLAINTEXT_EXPORT_FLAG | NCRYPT_ALLOW_EXPORT_FLAG;
    NCryptSetProperty(hKey, NCRYPT_EXPORT_POLICY_PROPERTY, (PBYTE)&ep, sizeof(ep), 0);
    st = NCryptFinalizeKey(hKey, 0);
    if (!NT_SUCCESS(st)) { NCryptFreeObject(hKey); NCryptFreeObject(hProv); return false; }

    const wchar_t* privBlobType = isECC ? BCRYPT_ECCPRIVATE_BLOB : BCRYPT_RSAPRIVATE_BLOB;
    DWORD cb = 0;
    NCryptExportKey(hKey, 0, privBlobType, NULL, NULL, 0, &cb, 0);
    std::vector<unsigned char> privBlob(cb);
    NCryptExportKey(hKey, 0, privBlobType, NULL, privBlob.data(), cb, &cb, 0);
    outPrivPem = WrapPem(BytesToBase64(privBlob.data(), privBlob.size()),
        isECC ? "EC PRIVATE KEY" : "RSA PRIVATE KEY");

    const wchar_t* pubBlobType = isECC ? BCRYPT_ECCPUBLIC_BLOB : BCRYPT_RSAPUBLIC_BLOB;
    cb = 0;
    NCryptExportKey(hKey, 0, pubBlobType, NULL, NULL, 0, &cb, 0);
    std::vector<unsigned char> pubBlob(cb);
    NCryptExportKey(hKey, 0, pubBlobType, NULL, pubBlob.data(), cb, &cb, 0);
    outPubPem = WrapPem(BytesToBase64(pubBlob.data(), pubBlob.size()), "PUBLIC KEY");

    std::vector<unsigned char> spki;
    if (isECC) {
        const unsigned char oidEcPubKey[] = { 0x2A, 0x86, 0x48, 0xCE, 0x3D, 0x02, 0x01 };
        std::vector<unsigned char> curveOid;
        if (wcscmp(ecCurve, BCRYPT_ECC_CURVE_NISTP256) == 0)
            curveOid = { 0x2A, 0x86, 0x48, 0xCE, 0x3D, 0x03, 0x01, 0x07 };
        else if (wcscmp(ecCurve, BCRYPT_ECC_CURVE_NISTP384) == 0)
            curveOid = { 0x2B, 0x81, 0x04, 0x00, 0x22 };
        else
            curveOid = { 0x2B, 0x81, 0x04, 0x00, 0x23 };

        auto algId = DerSequence({
            DerOid(oidEcPubKey, sizeof(oidEcPubKey)),
            DerOid(curveOid.data(), curveOid.size())
        });

        DWORD keySize = 32;
        if (wcscmp(ecCurve, BCRYPT_ECC_CURVE_NISTP384) == 0) keySize = 48;
        else if (wcscmp(ecCurve, BCRYPT_ECC_CURVE_NISTP521) == 0) keySize = 66;

        std::vector<unsigned char> point;
        point.push_back(0x04);
        BYTE* x = pubBlob.data() + sizeof(BCRYPT_ECCKEY_BLOB);
        BYTE* y = x + keySize;
        point.insert(point.end(), x, x + keySize);
        point.insert(point.end(), y, y + keySize);

        spki = DerSequence({
            algId,
            DerBitString(point)
        });
    } else {
        const unsigned char oidRsa[] = { 0x2A, 0x86, 0x48, 0x86, 0xF7, 0x0D, 0x01, 0x01, 0x01 };
        BCRYPT_RSAKEY_BLOB* rsaBlob = (BCRYPT_RSAKEY_BLOB*)pubBlob.data();
        BYTE* modulus = pubBlob.data() + sizeof(BCRYPT_RSAKEY_BLOB);
        BYTE* exp = modulus + rsaBlob->cbModulus;

        auto algId = DerSequence({
            DerOid(oidRsa, sizeof(oidRsa)),
        });

        std::vector<unsigned char> rsaPubKey = DerSequence({
            DerInteger(std::vector<unsigned char>(modulus, modulus + rsaBlob->cbModulus)),
            DerInteger(std::vector<unsigned char>(exp, exp + rsaBlob->cbPublicExp))
        });

        spki = DerSequence({
            algId,
            DerBitString(rsaPubKey)
        });
    }

    auto MakeRdn = [](const unsigned char* oidBytes, size_t oidLen, const std::wstring& value) -> std::vector<unsigned char> {
        std::string utf8 = WstringToUtf8(value);
        auto atv = DerSequence({
            DerOid(oidBytes, oidLen),
            DerUtf8String(utf8)
        });
        return DerSet(atv);
    };

    std::vector<std::vector<unsigned char>> nameRdns;
    if (!cn.empty()) {
        static const unsigned char oid[] = { 0x55, 0x04, 0x03 };
        nameRdns.push_back(MakeRdn(oid, sizeof(oid), cn));
    }
    if (!org.empty()) {
        static const unsigned char oid[] = { 0x55, 0x04, 0x0A };
        nameRdns.push_back(MakeRdn(oid, sizeof(oid), org));
    }
    if (!ou.empty()) {
        static const unsigned char oid[] = { 0x55, 0x04, 0x0B };
        nameRdns.push_back(MakeRdn(oid, sizeof(oid), ou));
    }
    if (!loc.empty()) {
        static const unsigned char oid[] = { 0x55, 0x04, 0x07 };
        nameRdns.push_back(MakeRdn(oid, sizeof(oid), loc));
    }
    if (!state.empty()) {
        static const unsigned char oid[] = { 0x55, 0x04, 0x08 };
        nameRdns.push_back(MakeRdn(oid, sizeof(oid), state));
    }
    if (!country.empty()) {
        static const unsigned char oid[] = { 0x55, 0x04, 0x06 };
        nameRdns.push_back(MakeRdn(oid, sizeof(oid), country));
    }
    if (!email.empty()) {
        static const unsigned char oid[] = { 0x2A, 0x86, 0x48, 0x86, 0xF7, 0x0D, 0x01, 0x09, 0x01 };
        nameRdns.push_back(MakeRdn(oid, sizeof(oid), email));
    }

    std::vector<unsigned char> nameContent;
    for (auto& rdn : nameRdns) nameContent.insert(nameContent.end(), rdn.begin(), rdn.end());
    auto subjectName = DerSequence({ nameContent });
    auto certReqInfo = DerSequence({
        DerIntegerFromSize(0),
        subjectName,
        spki
    });

    auto hash = Sha256Hash(certReqInfo.data(), certReqInfo.size());

    BCRYPT_PKCS1_PADDING_INFO padInfo = {};
    if (isECC) {
        if (keyIdx == 3) padInfo.pszAlgId = BCRYPT_SHA256_ALGORITHM;
        else if (keyIdx == 4) padInfo.pszAlgId = BCRYPT_SHA384_ALGORITHM;
        else padInfo.pszAlgId = BCRYPT_SHA512_ALGORITHM;
    } else {
        padInfo.pszAlgId = BCRYPT_SHA256_ALGORITHM;
    }

    DWORD signFlags = isECC ? 0 : BCRYPT_PAD_PKCS1;
    cb = 0;
    st = NCryptSignHash(hKey, &padInfo, hash.data(), (ULONG)hash.size(), NULL, 0, &cb, signFlags);
    if (!NT_SUCCESS(st)) { NCryptFreeObject(hKey); NCryptFreeObject(hProv); return false; }

    std::vector<unsigned char> sig(cb);
    st = NCryptSignHash(hKey, &padInfo, hash.data(), (ULONG)hash.size(), sig.data(), cb, &cb, signFlags);
    if (!NT_SUCCESS(st)) { NCryptFreeObject(hKey); NCryptFreeObject(hProv); return false; }

    std::vector<unsigned char> sigAlgSeq;
    if (isECC) {
        const unsigned char oidEcdsa[] = { 0x2A, 0x86, 0x48, 0xCE, 0x3D, 0x04, 0x01 };
        const unsigned char oidSha256[] = { 0x60, 0x86, 0x48, 0x01, 0x65, 0x03, 0x04, 0x02, 0x01 };
        const unsigned char oidSha384[] = { 0x60, 0x86, 0x48, 0x01, 0x65, 0x03, 0x04, 0x02, 0x02 };
        const unsigned char oidSha512[] = { 0x60, 0x86, 0x48, 0x01, 0x65, 0x03, 0x04, 0x02, 0x03 };
        const unsigned char* hashOid = oidSha256; size_t hashOidLen = sizeof(oidSha256);
        if (keyIdx == 4) { hashOid = oidSha384; hashOidLen = sizeof(oidSha384); }
        if (keyIdx == 5) { hashOid = oidSha512; hashOidLen = sizeof(oidSha512); }
        sigAlgSeq = DerSequence({
            DerOid(oidEcdsa, sizeof(oidEcdsa)),
            DerOid(hashOid, hashOidLen)
        });
    } else {
        const unsigned char oidSha256Rsa[] = { 0x2A, 0x86, 0x48, 0x86, 0xF7, 0x0D, 0x01, 0x01, 0x0B };
        sigAlgSeq = DerSequence({
            DerOid(oidSha256Rsa, sizeof(oidSha256Rsa))
        });
    }

    auto csr = DerSequence({
        certReqInfo,
        sigAlgSeq,
        DerBitString(sig)
    });

    outCsrPem = WrapPem(BytesToBase64(csr.data(), csr.size()), "CERTIFICATE REQUEST");

    std::ostringstream oss;
    oss << "=== Certificate Signing Request (CSR) ===\r\n\r\n";
    oss << "--- CSR (PEM) ---\r\n" << outCsrPem << "\r\n\r\n";
    oss << "--- Private Key (PEM) ---\r\n" << outPrivPem << "\r\n\r\n";
    oss << "--- Public Key (PEM) ---\r\n" << outPubPem << "\r\n\r\n";
    oss << "--- Details ---\r\n";
    oss << "Subject: " << WstringToUtf8(cn.empty() ? L"(none)" : cn);
    if (!org.empty()) oss << ", O=" << WstringToUtf8(org);
    if (!ou.empty()) oss << ", OU=" << WstringToUtf8(ou);
    if (!loc.empty()) oss << ", L=" << WstringToUtf8(loc);
    if (!state.empty()) oss << ", S=" << WstringToUtf8(state);
    if (!country.empty()) oss << ", C=" << WstringToUtf8(country);
    if (!email.empty()) oss << ", E=" << WstringToUtf8(email);
    oss << "\r\n";
    oss << "Algorithm: " << (isECC ? "ECDSA" : "RSA") << "\r\n";
    if (isECC) oss << "Curve: " << WstringToUtf8(ecCurve) << "\r\n";
    else oss << "Key Size: " << rsaBits << " bits\r\n";
    outInfo = oss.str();

    NCryptFreeObject(hKey);
    NCryptFreeObject(hProv);
    return true;
}

void HandleCSR(HWND hwnd) {
    CSRDlgCtx ctx = {};
    if (!OpenCSRDialog(hwnd, &ctx)) return;

    std::string csrPem, privPem, pubPem, info;
    if (!BuildCSR(ctx.cn, ctx.org, ctx.ou,
        ctx.loc, ctx.state, ctx.country, ctx.email,
        ctx.keyIdx, csrPem, privPem, pubPem, info)) {
        SetStatus(L"CSR: Key generation or CSR creation failed.");
        return;
    }

    SetEditText(hOutputEdit, Utf8ToWstring(info));
    SetStatus(L"CSR generated successfully.");
}

static std::vector<BYTE> base64_decode_der(const std::string& b64) {
    std::string decoded = base64_decode(b64);
    return std::vector<BYTE>(decoded.begin(), decoded.end());
}

// ===== PKCS#7 Bundle =====
static std::string ReadFileToString(const std::wstring& path);
struct PKCS7DlgCtx {
    HWND hInput;
    HWND hFileEdit;
    bool confirmed;
    std::wstring input;
};

static const wchar_t PKCS7_DLG_CLASS[] = L"PKCS7DialogClass";
static bool pkcs7DlgClassRegistered = false;

static std::vector<std::string> ExtractPemCerts(const std::string& pem) {
    std::vector<std::string> certs;
    size_t pos = 0;
    while (true) {
        size_t begin = pem.find("-----BEGIN CERTIFICATE-----", pos);
        if (begin == std::string::npos) break;
        size_t end = pem.find("-----END CERTIFICATE-----", begin);
        if (end == std::string::npos) break;
        std::string b64 = pem.substr(begin + 28, end - begin - 28);
        std::string cleaned;
        for (char c : b64) if (!isspace((unsigned char)c)) cleaned.push_back(c);
        certs.push_back(cleaned);
        pos = end + 25;
    }
    return certs;
}

LRESULT CALLBACK PKCS7DlgProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
    PKCS7DlgCtx* ctx = NULL;
    if (msg == WM_NCCREATE) {
        ctx = (PKCS7DlgCtx*)((CREATESTRUCTW*)lParam)->lpCreateParams;
        SetWindowLongPtr(hwnd, GWLP_USERDATA, (LONG_PTR)ctx);
        return DefWindowProcW(hwnd, msg, wParam, lParam);
    }
    ctx = (PKCS7DlgCtx*)GetWindowLongPtr(hwnd, GWLP_USERDATA);
    if (!ctx) return DefWindowProcW(hwnd, msg, wParam, lParam);

    switch (msg) {
    case WM_CREATE: {
        HFONT hf = hBoldFont ? hBoldFont : (HFONT)GetStockObject(DEFAULT_GUI_FONT);
        HFONT hnf = hFont ? hFont : (HFONT)GetStockObject(SYSTEM_FONT);
        int y = 10;

        HWND hLbl = CreateWindowW(L"STATIC",
            L"PEM Certificate File:",
            WS_CHILD | WS_VISIBLE, 10, y + 3, 135, 20, hwnd, NULL, NULL, NULL);
        SendMessage(hLbl, WM_SETFONT, (WPARAM)hf, TRUE);

        ctx->hFileEdit = CreateWindowExW(WS_EX_CLIENTEDGE, L"EDIT", L"",
            WS_CHILD | WS_VISIBLE | WS_TABSTOP, 145, y, 300, 23, hwnd, (HMENU)(INT_PTR)IDC_PKCS7_FILE_EDIT, NULL, NULL);
        SendMessage(ctx->hFileEdit, WM_SETFONT, (WPARAM)hnf, TRUE);

        HWND hBrowse = CreateWindowW(L"BUTTON", L"Browse...",
            WS_CHILD | WS_VISIBLE | WS_TABSTOP, 455, y, 80, 25, hwnd, (HMENU)(INT_PTR)IDC_PKCS7_BROWSE_BTN, NULL, NULL);
        SendMessage(hBrowse, WM_SETFONT, (WPARAM)hf, TRUE);
        y += 30;

        HWND hLbl2 = CreateWindowW(L"STATIC",
            L"Or paste PEM certificate(s) below:",
            WS_CHILD | WS_VISIBLE, 10, y + 3, 400, 20, hwnd, NULL, NULL, NULL);
        SendMessage(hLbl2, WM_SETFONT, (WPARAM)hf, TRUE);
        y += 22;

        ctx->hInput = CreateWindowExW(WS_EX_CLIENTEDGE, L"EDIT", L"",
            WS_CHILD | WS_VISIBLE | WS_VSCROLL | WS_HSCROLL |
            ES_MULTILINE | ES_AUTOVSCROLL | WS_TABSTOP,
            10, y, 570, 250, hwnd, (HMENU)(INT_PTR)IDC_PKCS7_INPUT, NULL, NULL);
        SendMessage(ctx->hInput, WM_SETFONT, (WPARAM)hnf, TRUE);

        HWND hBtn = CreateWindowW(L"BUTTON", L"Create PKCS#7",
            WS_CHILD | WS_VISIBLE | WS_TABSTOP | BS_DEFPUSHBUTTON,
            10, 345, 130, 30, hwnd, (HMENU)(INT_PTR)IDC_PKCS7_CREATE_BTN, NULL, NULL);
        SendMessage(hBtn, WM_SETFONT, (WPARAM)hf, TRUE);

        HWND hCancel = CreateWindowW(L"BUTTON", L"Cancel",
            WS_CHILD | WS_VISIBLE | WS_TABSTOP,
            150, 345, 90, 30, hwnd, (HMENU)(INT_PTR)IDC_PKCS7_CANCEL_BTN, NULL, NULL);
        SendMessage(hCancel, WM_SETFONT, (WPARAM)hf, TRUE);

        SetFocus(ctx->hInput);
        return 0;
    }
    case WM_COMMAND:
        if (ctx) {
            if (LOWORD(wParam) == IDC_PKCS7_BROWSE_BTN) {
                wchar_t fn[MAX_PATH] = L"";
                OPENFILENAMEW ofn = {}; ofn.lStructSize = sizeof(ofn);
                ofn.hwndOwner = hwnd;
                ofn.lpstrFilter = L"PEM Files (*.pem)\0*.pem\0All Files (*.*)\0*.*\0";
                ofn.lpstrTitle = L"Select PEM Certificate File";
                ofn.lpstrFile = fn; ofn.nMaxFile = MAX_PATH;
                ofn.Flags = OFN_FILEMUSTEXIST | OFN_PATHMUSTEXIST;
                if (GetOpenFileNameW(&ofn)) SetWindowTextW(ctx->hFileEdit, fn);
                return 0;
            }
            if (LOWORD(wParam) == IDC_PKCS7_CREATE_BTN || LOWORD(wParam) == IDOK) {
                std::wstring filePath = GetEditText(ctx->hFileEdit);
                std::wstring pasted = GetEditText(ctx->hInput);
                std::string allPem;
                if (!filePath.empty()) {
                    std::string fileContent = ReadFileToString(filePath);
                    if (!fileContent.empty()) allPem += fileContent;
                    else MessageBoxW(hwnd, (L"Failed to read file: " + filePath).c_str(), L"PKCS#7", MB_ICONERROR);
                }
                if (!pasted.empty()) {
                    if (!allPem.empty()) allPem += "\r\n";
                    allPem += WstringToUtf8(pasted);
                }
                if (allPem.empty()) {
                    MessageBoxW(hwnd, L"Please select a PEM file or paste PEM certificate(s).", L"PKCS#7", MB_ICONINFORMATION);
                    return 0;
                }
                ctx->input = Utf8ToWstring(allPem);
                ctx->confirmed = true;
                DestroyWindow(hwnd);
                return 0;
            }
            if (LOWORD(wParam) == IDC_PKCS7_CANCEL_BTN || LOWORD(wParam) == IDCANCEL) { DestroyWindow(hwnd); return 0; }
        }
        break;
    case WM_SIZE: {
        RECT rc; GetClientRect(hwnd, &rc);
        int cw = rc.right, ch = rc.bottom;
        int pad = 10, btnH = 30, browseW = 80;
        HWND hChild = GetWindow(hwnd, GW_CHILD);
        while (hChild) {
            HWND hNext = GetWindow(hChild, GW_HWNDNEXT);
            wchar_t cls[32] = {};
            GetClassNameW(hChild, cls, 32);
            RECT cr = {}; GetWindowRect(hChild, &cr);
            ScreenToClient(hwnd, (POINT*)&cr);
            int origX = cr.left, origY = cr.top, origW = cr.right - cr.left, origH = cr.bottom - cr.top;
            int ctrlId = GetDlgCtrlID(hChild);
            if (ctrlId == IDC_PKCS7_INPUT) {
                MoveWindow(hChild, pad, origY, cw - pad * 2, ch - origY - btnH - pad * 2, TRUE);
            } else if (ctrlId == IDC_PKCS7_CREATE_BTN || ctrlId == IDC_PKCS7_CANCEL_BTN) {
                MoveWindow(hChild, origX, ch - btnH - pad, origW, btnH, TRUE);
            } else if (ctrlId == IDC_PKCS7_BROWSE_BTN) {
                MoveWindow(hChild, cw - browseW - pad, origY, browseW, origH, TRUE);
            } else if (wcscmp(cls, L"EDIT") == 0) {
                int newW = cw - origX - browseW - pad - 8;
                if (newW < 100) newW = 100;
                MoveWindow(hChild, origX, origY, newW, origH, TRUE);
            }
            hChild = hNext;
        }
        break;
    }
    case WM_CLOSE: DestroyWindow(hwnd); return 0;
    }
    return DefWindowProcW(hwnd, msg, wParam, lParam);
}

bool OpenPKCS7Dialog(HWND parent, PKCS7DlgCtx* ctx) {
    if (!pkcs7DlgClassRegistered) {
        WNDCLASSEXW wc = {};
        wc.cbSize = sizeof(wc);
        wc.lpfnWndProc = PKCS7DlgProc;
        wc.hInstance = g_hInstance;
        wc.hCursor = LoadCursor(NULL, IDC_ARROW);
        wc.hbrBackground = (HBRUSH)(COLOR_BTNFACE + 1);
        wc.lpszClassName = PKCS7_DLG_CLASS;
        RegisterClassExW(&wc);
        pkcs7DlgClassRegistered = true;
    }
    int screenW = GetSystemMetrics(SM_CXSCREEN);
    int screenH = GetSystemMetrics(SM_CYSCREEN);
    int dlgW = 720, dlgH = 500;
    HWND hDlg = CreateWindowExW(WS_EX_DLGMODALFRAME | WS_EX_TOPMOST,
        PKCS7_DLG_CLASS, L"Create PKCS#7 Certificate Bundle",
        WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU | WS_THICKFRAME | WS_MAXIMIZEBOX,
        (screenW - dlgW) / 2, (screenH - dlgH) / 2, dlgW, dlgH,
        parent, NULL, g_hInstance, ctx);
    if (!hDlg) return false;
    EnableWindow(parent, FALSE);
    ShowWindow(hDlg, SW_SHOW);
    MSG msg;
    while (IsWindow(hDlg)) {
        BOOL ret = GetMessageW(&msg, NULL, 0, 0);
        if (ret == 0 || ret == -1) break;
        if (!IsWindow(hDlg)) break;
        if (!IsDialogMessageW(hDlg, &msg)) { TranslateMessage(&msg); DispatchMessageW(&msg); }
    }
    EnableWindow(parent, TRUE);
    SetForegroundWindow(parent);
    return ctx->confirmed;
}

void HandlePKCS7(HWND hwnd) {
    PKCS7DlgCtx ctx = {};
    if (!OpenPKCS7Dialog(hwnd, &ctx)) return;

    std::wstring inputW = ctx.input;
    std::string input = WstringToUtf8(inputW);
    auto certB64s = ExtractPemCerts(input);
    if (certB64s.empty()) { SetStatus(L"PKCS#7: No PEM certificates found in input."); return; }

    HCERTSTORE hMemStore = CertOpenStore(
        CERT_STORE_PROV_MEMORY, X509_ASN_ENCODING | PKCS_7_ASN_ENCODING,
        0, 0, NULL);
    if (!hMemStore) { SetStatus(L"PKCS#7: Failed to open memory store. Error " + std::to_wstring(GetLastError())); return; }

    int certCount = 0;
    for (auto& b64 : certB64s) {
        std::vector<BYTE> der = base64_decode_der(b64);
        PCCERT_CONTEXT pCert = CertCreateCertificateContext(
            X509_ASN_ENCODING | PKCS_7_ASN_ENCODING, der.data(), (DWORD)der.size());
        if (pCert) {
            CertAddCertificateContextToStore(hMemStore, pCert, CERT_STORE_ADD_NEW, NULL);
            CertFreeCertificateContext(pCert);
            certCount++;
        }
    }

    if (certCount == 0) {
        CertCloseStore(hMemStore, 0);
        SetStatus(L"PKCS#7: No valid certificates could be parsed.");
        return;
    }

    CRYPT_DATA_BLOB blob = {0, NULL};
    CertSaveStore(hMemStore, X509_ASN_ENCODING | PKCS_7_ASN_ENCODING,
        CERT_STORE_SAVE_AS_PKCS7, CERT_STORE_SAVE_TO_MEMORY, &blob, 0);
    blob.pbData = (BYTE*)malloc(blob.cbData);
    if (!blob.pbData) {
        CertCloseStore(hMemStore, 0);
        SetStatus(L"PKCS#7: Memory allocation failed.");
        return;
    }
    BOOL ok = CertSaveStore(hMemStore, X509_ASN_ENCODING | PKCS_7_ASN_ENCODING,
        CERT_STORE_SAVE_AS_PKCS7, CERT_STORE_SAVE_TO_MEMORY, &blob, 0);
    CertCloseStore(hMemStore, 0);

    if (!ok || blob.cbData == 0) {
        free(blob.pbData);
        SetStatus(L"PKCS#7: Failed to save store. Error " + std::to_wstring(GetLastError()));
        return;
    }

    std::string pkcs7Pem = WrapPem(BytesToBase64(blob.pbData, blob.cbData), "PKCS7");
    free(blob.pbData);

    std::ostringstream oss;
    oss << "=== PKCS#7 Certificate Bundle ===\r\n\r\n";
    oss << "Certificates included: " << certCount << "\r\n\r\n";
    oss << "--- PKCS#7 (PEM) ---\r\n" << pkcs7Pem << "\r\n";

    SetEditText(hOutputEdit, Utf8ToWstring(oss.str()));
    SetStatus(L"PKCS#7 bundle created with " + std::to_wstring(certCount) + L" certificate(s).");
}

// ===== Additional DER helpers for X.509 =====
static std::vector<unsigned char> DerOctetString(const std::vector<unsigned char>& data) {
    return DerWrap(0x04, data);
}

static std::vector<unsigned char> DerExplicitTag(unsigned char tagNum, const std::vector<unsigned char>& content) {
    return DerWrap(0xA0 | tagNum, content);
}

static std::vector<unsigned char> DerUtcTime(const SYSTEMTIME& st) {
    char buf[14];
    snprintf(buf, sizeof(buf), "%02d%02d%02d%02d%02d%02dZ",
        st.wYear % 100, st.wMonth, st.wDay, st.wHour, st.wMinute, st.wSecond);
    return DerWrap(0x17, std::vector<unsigned char>(buf, buf + 13));
}

static std::vector<unsigned char> DerBoolean(bool val) {
    return DerWrap(0x01, std::vector<unsigned char>{ (unsigned char)(val ? 0xFF : 0x00) });
}

static std::vector<unsigned char> DerIA5String(const std::string& s) {
    return DerWrap(0x16, std::vector<unsigned char>(s.begin(), s.end()));
}

// ===== CA Certificate =====
struct CADlgCtx {
    HWND hCN, hOrg, hOU, hLoc, hState, hCountry, hEmail;
    HWND hKeyCombo, hValidityEdit;
    bool confirmed;
    std::wstring cn, org, ou, loc, state, country, email;
    int keyIdx, validityYears;
};

static const wchar_t CA_DLG_CLASS[] = L"CADialogClass";
static bool caDlgClassRegistered = false;

LRESULT CALLBACK CADlgProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
    CADlgCtx* ctx = NULL;
    if (msg == WM_NCCREATE) {
        ctx = (CADlgCtx*)((CREATESTRUCTW*)lParam)->lpCreateParams;
        SetWindowLongPtr(hwnd, GWLP_USERDATA, (LONG_PTR)ctx);
        return DefWindowProcW(hwnd, msg, wParam, lParam);
    }
    ctx = (CADlgCtx*)GetWindowLongPtr(hwnd, GWLP_USERDATA);
    if (!ctx) return DefWindowProcW(hwnd, msg, wParam, lParam);

    switch (msg) {
    case WM_CREATE: {
        HFONT hf = hBoldFont ? hBoldFont : (HFONT)GetStockObject(DEFAULT_GUI_FONT);
        HFONT hnf = hFont ? hFont : (HFONT)GetStockObject(SYSTEM_FONT);
        int y = 10;

        auto addLabel = [&](const wchar_t* text, int lblW) {
            HWND h = CreateWindowW(L"STATIC", text, WS_CHILD | WS_VISIBLE, 10, y + 3, lblW, 20, hwnd, NULL, NULL, NULL);
            SendMessage(h, WM_SETFONT, (WPARAM)hf, TRUE);
        };
        auto addEdit = [&](int id, int exW) {
            HWND h = CreateWindowExW(WS_EX_CLIENTEDGE, L"EDIT", L"",
                WS_CHILD | WS_VISIBLE | WS_TABSTOP, 10 + 120, y, exW, 23, hwnd, (HMENU)(INT_PTR)id, NULL, NULL);
            SendMessage(h, WM_SETFONT, (WPARAM)hnf, TRUE);
            return h;
        };

        addLabel(L"Common Name (CN):", 115); ctx->hCN = addEdit(IDC_CA_CN, 365); y += 28;
        addLabel(L"Organization (O):", 115); ctx->hOrg = addEdit(IDC_CA_ORG, 365); y += 28;
        addLabel(L"Org Unit (OU):", 115); ctx->hOU = addEdit(IDC_CA_OU, 365); y += 28;
        addLabel(L"Locality (L):", 115); ctx->hLoc = addEdit(IDC_CA_LOCALITY, 365); y += 28;
        addLabel(L"State (S):", 115); ctx->hState = addEdit(IDC_CA_STATE, 365); y += 28;
        addLabel(L"Country (C):", 115); ctx->hCountry = addEdit(IDC_CA_COUNTRY, 365); y += 28;
        addLabel(L"Email (E):", 115); ctx->hEmail = addEdit(IDC_CA_EMAIL, 365); y += 33;

        addLabel(L"Key Type:", 115);
        ctx->hKeyCombo = CreateWindowExW(0, L"COMBOBOX", L"",
            WS_CHILD | WS_VISIBLE | WS_TABSTOP | CBS_DROPDOWNLIST,
            10 + 120, y, 200, 200, hwnd, (HMENU)(INT_PTR)IDC_CA_KEYTYPE, NULL, NULL);
        SendMessage(ctx->hKeyCombo, WM_SETFONT, (WPARAM)hnf, TRUE);
        const wchar_t* keyTypes[] = {
            L"RSA 2048", L"RSA 3072", L"RSA 4096",
            L"ECDSA P-256", L"ECDSA P-384", L"ECDSA P-521"
        };
        for (auto& kt : keyTypes) SendMessageW(ctx->hKeyCombo, CB_ADDSTRING, 0, (LPARAM)kt);
        SendMessage(ctx->hKeyCombo, CB_SETCURSEL, 0, 0);
        y += 33;

        addLabel(L"Validity (years):", 115);
        ctx->hValidityEdit = CreateWindowExW(WS_EX_CLIENTEDGE, L"EDIT", L"10",
            WS_CHILD | WS_VISIBLE | WS_TABSTOP | ES_NUMBER,
            10 + 120, y, 60, 23, hwnd, (HMENU)(INT_PTR)IDC_CA_VALIDITY, NULL, NULL);
        SendMessage(ctx->hValidityEdit, WM_SETFONT, (WPARAM)hnf, TRUE);
        y += 38;

        HWND hBtn = CreateWindowW(L"BUTTON", L"Create CA Certificate",
            WS_CHILD | WS_VISIBLE | WS_TABSTOP | BS_DEFPUSHBUTTON,
            10, y, 160, 30, hwnd, (HMENU)(INT_PTR)IDC_CA_GENERATE, NULL, NULL);
        SendMessage(hBtn, WM_SETFONT, (WPARAM)hf, TRUE);

        HWND hCancel = CreateWindowW(L"BUTTON", L"Cancel",
            WS_CHILD | WS_VISIBLE | WS_TABSTOP,
            180, y, 90, 30, hwnd, (HMENU)(INT_PTR)IDC_CA_CANCEL, NULL, NULL);
        SendMessage(hCancel, WM_SETFONT, (WPARAM)hf, TRUE);

        SetFocus(ctx->hCN);
        return 0;
    }
    case WM_COMMAND:
        if (ctx) {
            if (LOWORD(wParam) == IDC_CA_GENERATE) {
                ctx->cn = GetEditText(ctx->hCN);
                if (ctx->cn.empty()) { MessageBoxW(hwnd, L"Common Name (CN) is required.", L"CA Certificate", MB_ICONINFORMATION); SetFocus(ctx->hCN); return 0; }
                ctx->org = GetEditText(ctx->hOrg);
                ctx->ou = GetEditText(ctx->hOU);
                ctx->loc = GetEditText(ctx->hLoc);
                ctx->state = GetEditText(ctx->hState);
                ctx->country = GetEditText(ctx->hCountry);
                ctx->email = GetEditText(ctx->hEmail);
                ctx->keyIdx = (int)SendMessageW(ctx->hKeyCombo, CB_GETCURSEL, 0, 0);
                wchar_t vbuf[16] = {};
                GetWindowTextW(ctx->hValidityEdit, vbuf, 16);
                ctx->validityYears = _wtoi(vbuf);
                ctx->confirmed = true;
                DestroyWindow(hwnd);
                return 0;
            }
            if (LOWORD(wParam) == IDC_CA_CANCEL || LOWORD(wParam) == IDCANCEL) { DestroyWindow(hwnd); return 0; }
        }
        break;
    case WM_SIZE: {
        RECT rc; GetClientRect(hwnd, &rc);
        int cw = rc.right, ch = rc.bottom;
        HWND hChild = GetWindow(hwnd, GW_CHILD);
        int bottomY = ch - 40;
        while (hChild) {
            HWND hNext = GetWindow(hChild, GW_HWNDNEXT);
            wchar_t cls[32] = {};
            GetClassNameW(hChild, cls, 32);
            RECT cr = {}; GetWindowRect(hChild, &cr);
            ScreenToClient(hwnd, (POINT*)&cr);
            int origY = cr.top;
            if (wcscmp(cls, L"BUTTON") == 0) {
                MoveWindow(hChild, cr.left, bottomY, cr.right - cr.left, cr.bottom - cr.top, TRUE);
            } else if (wcscmp(cls, L"EDIT") == 0 || wcscmp(cls, L"COMBOBOX") == 0) {
                int newW = cw - cr.left - 12;
                if (newW < 80) newW = 80;
                MoveWindow(hChild, cr.left, origY, newW, cr.bottom - cr.top, TRUE);
            }
            hChild = hNext;
        }
        break;
    }
    case WM_CLOSE: DestroyWindow(hwnd); return 0;
    }
    return DefWindowProcW(hwnd, msg, wParam, lParam);
}

bool OpenCADialog(HWND parent, CADlgCtx* ctx) {
    if (!caDlgClassRegistered) {
        WNDCLASSEXW wc = {};
        wc.cbSize = sizeof(wc);
        wc.lpfnWndProc = CADlgProc;
        wc.hInstance = g_hInstance;
        wc.hCursor = LoadCursor(NULL, IDC_ARROW);
        wc.hbrBackground = (HBRUSH)(COLOR_BTNFACE + 1);
        wc.lpszClassName = CA_DLG_CLASS;
        RegisterClassExW(&wc);
        caDlgClassRegistered = true;
    }
    int screenW = GetSystemMetrics(SM_CXSCREEN);
    int screenH = GetSystemMetrics(SM_CYSCREEN);
    int dlgW = 640, dlgH = 440;
    HWND hDlg = CreateWindowExW(WS_EX_DLGMODALFRAME | WS_EX_TOPMOST,
        CA_DLG_CLASS, L"Create CA Certificate",
        WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU | WS_THICKFRAME | WS_MAXIMIZEBOX,
        (screenW - dlgW) / 2, (screenH - dlgH) / 2, dlgW, dlgH,
        parent, NULL, g_hInstance, ctx);
    if (!hDlg) return false;
    EnableWindow(parent, FALSE);
    ShowWindow(hDlg, SW_SHOW);
    MSG msg;
    while (IsWindow(hDlg)) {
        BOOL ret = GetMessageW(&msg, NULL, 0, 0);
        if (ret == 0 || ret == -1) break;
        if (!IsWindow(hDlg)) break;
        if (!IsDialogMessageW(hDlg, &msg)) { TranslateMessage(&msg); DispatchMessageW(&msg); }
    }
    EnableWindow(parent, TRUE);
    SetForegroundWindow(parent);
    return ctx->confirmed;
}

// X.500 Name OID bytes
static const unsigned char oidCN[] = { 0x55, 0x04, 0x03 };
static const unsigned char oidO[] = { 0x55, 0x04, 0x0A };
static const unsigned char oidOU[] = { 0x55, 0x04, 0x0B };
static const unsigned char oidL[] = { 0x55, 0x04, 0x07 };
static const unsigned char oidS[] = { 0x55, 0x04, 0x08 };
static const unsigned char oidC[] = { 0x55, 0x04, 0x06 };
static const unsigned char oidE[] = { 0x2A, 0x86, 0x48, 0x86, 0xF7, 0x0D, 0x01, 0x09, 0x01 };

static void AddNameRdn(std::vector<std::vector<unsigned char>>& nameRdns,
    const unsigned char* oid, size_t oidLen, const std::wstring& value)
{
    if (value.empty()) return;
    std::string utf8 = WstringToUtf8(value);
    auto atv = DerSequence({ DerOid(oid, oidLen), DerUtf8String(utf8) });
    nameRdns.push_back(DerSet(atv));
}

static bool BuildCACert(
    const std::wstring& cn, const std::wstring& org, const std::wstring& ou,
    const std::wstring& loc, const std::wstring& state, const std::wstring& country,
    const std::wstring& email, int keyIdx, int validityYears,
    std::string& outCertPem, std::string& outPrivPem, std::string& outPubPem, std::string& outInfo)
{
    const wchar_t* ncryptAlgo = BCRYPT_RSA_ALGORITHM;
    const wchar_t* ecCurve = NULL;
    int rsaBits = 2048;
    bool isECC = false;

    switch (keyIdx) {
    case 0: rsaBits = 2048; break;
    case 1: rsaBits = 3072; break;
    case 2: rsaBits = 4096; break;
    case 3: ncryptAlgo = BCRYPT_ECDSA_ALGORITHM; ecCurve = BCRYPT_ECC_CURVE_NISTP256; isECC = true; break;
    case 4: ncryptAlgo = BCRYPT_ECDSA_ALGORITHM; ecCurve = BCRYPT_ECC_CURVE_NISTP384; isECC = true; break;
    case 5: ncryptAlgo = BCRYPT_ECDSA_ALGORITHM; ecCurve = BCRYPT_ECC_CURVE_NISTP521; isECC = true; break;
    }

    NCRYPT_PROV_HANDLE hProv = 0;
    NCRYPT_KEY_HANDLE hKey = 0;
    NTSTATUS st;

    st = NCryptOpenStorageProvider(&hProv, MS_KEY_STORAGE_PROVIDER, 0);
    if (!NT_SUCCESS(st)) return false;

    st = NCryptCreatePersistedKey(hProv, &hKey, ncryptAlgo, NULL, 0, 0);
    if (!NT_SUCCESS(st)) { NCryptFreeObject(hProv); return false; }

    if (isECC) {
        st = NCryptSetProperty(hKey, NCRYPT_ECC_CURVE_NAME_PROPERTY, (PBYTE)ecCurve,
            (DWORD)((wcslen(ecCurve) + 1) * sizeof(wchar_t)), 0);
    } else {
        st = NCryptSetProperty(hKey, NCRYPT_LENGTH_PROPERTY, (PBYTE)&rsaBits, sizeof(rsaBits), 0);
    }
    if (!NT_SUCCESS(st)) { NCryptFreeObject(hKey); NCryptFreeObject(hProv); return false; }

    DWORD ep = NCRYPT_ALLOW_PLAINTEXT_EXPORT_FLAG | NCRYPT_ALLOW_EXPORT_FLAG;
    NCryptSetProperty(hKey, NCRYPT_EXPORT_POLICY_PROPERTY, (PBYTE)&ep, sizeof(ep), 0);
    st = NCryptFinalizeKey(hKey, 0);
    if (!NT_SUCCESS(st)) { NCryptFreeObject(hKey); NCryptFreeObject(hProv); return false; }

    const wchar_t* privBlobType = isECC ? BCRYPT_ECCPRIVATE_BLOB : BCRYPT_RSAPRIVATE_BLOB;
    DWORD cb = 0;
    NCryptExportKey(hKey, 0, privBlobType, NULL, NULL, 0, &cb, 0);
    std::vector<unsigned char> privBlob(cb);
    NCryptExportKey(hKey, 0, privBlobType, NULL, privBlob.data(), cb, &cb, 0);
    outPrivPem = WrapPem(BytesToBase64(privBlob.data(), privBlob.size()),
        isECC ? "EC PRIVATE KEY" : "RSA PRIVATE KEY");

    const wchar_t* pubBlobType = isECC ? BCRYPT_ECCPUBLIC_BLOB : BCRYPT_RSAPUBLIC_BLOB;
    cb = 0;
    NCryptExportKey(hKey, 0, pubBlobType, NULL, NULL, 0, &cb, 0);
    std::vector<unsigned char> pubBlob(cb);
    NCryptExportKey(hKey, 0, pubBlobType, NULL, pubBlob.data(), cb, &cb, 0);
    outPubPem = WrapPem(BytesToBase64(pubBlob.data(), pubBlob.size()), "PUBLIC KEY");

    // Build SPKI
    std::vector<unsigned char> spki;
    if (isECC) {
        const unsigned char oidEcPubKey[] = { 0x2A, 0x86, 0x48, 0xCE, 0x3D, 0x02, 0x01 };
        std::vector<unsigned char> curveOid;
        if (wcscmp(ecCurve, BCRYPT_ECC_CURVE_NISTP256) == 0)
            curveOid = { 0x2A, 0x86, 0x48, 0xCE, 0x3D, 0x03, 0x01, 0x07 };
        else if (wcscmp(ecCurve, BCRYPT_ECC_CURVE_NISTP384) == 0)
            curveOid = { 0x2B, 0x81, 0x04, 0x00, 0x22 };
        else
            curveOid = { 0x2B, 0x81, 0x04, 0x00, 0x23 };

        auto algId = DerSequence({ DerOid(oidEcPubKey, sizeof(oidEcPubKey)), DerOid(curveOid.data(), curveOid.size()) });

        DWORD keySize = 32;
        if (wcscmp(ecCurve, BCRYPT_ECC_CURVE_NISTP384) == 0) keySize = 48;
        else if (wcscmp(ecCurve, BCRYPT_ECC_CURVE_NISTP521) == 0) keySize = 66;

        std::vector<unsigned char> point;
        point.push_back(0x04);
        BYTE* x = pubBlob.data() + sizeof(BCRYPT_ECCKEY_BLOB);
        BYTE* y = x + keySize;
        point.insert(point.end(), x, x + keySize);
        point.insert(point.end(), y, y + keySize);

        spki = DerSequence({ algId, DerBitString(point) });
    } else {
        const unsigned char oidRsa[] = { 0x2A, 0x86, 0x48, 0x86, 0xF7, 0x0D, 0x01, 0x01, 0x01 };
        BCRYPT_RSAKEY_BLOB* rsaBlob = (BCRYPT_RSAKEY_BLOB*)pubBlob.data();
        BYTE* modulus = pubBlob.data() + sizeof(BCRYPT_RSAKEY_BLOB);
        BYTE* exp = modulus + rsaBlob->cbModulus;

        auto algId = DerSequence({ DerOid(oidRsa, sizeof(oidRsa)) });
        auto rsaPubKey = DerSequence({
            DerInteger(std::vector<unsigned char>(modulus, modulus + rsaBlob->cbModulus)),
            DerInteger(std::vector<unsigned char>(exp, exp + rsaBlob->cbPublicExp))
        });
        spki = DerSequence({ algId, DerBitString(rsaPubKey) });
    }

    // Build subject name
    std::vector<std::vector<unsigned char>> nameRdns;
    AddNameRdn(nameRdns, oidCN, sizeof(oidCN), cn);
    AddNameRdn(nameRdns, oidO, sizeof(oidO), org);
    AddNameRdn(nameRdns, oidOU, sizeof(oidOU), ou);
    AddNameRdn(nameRdns, oidL, sizeof(oidL), loc);
    AddNameRdn(nameRdns, oidS, sizeof(oidS), state);
    AddNameRdn(nameRdns, oidC, sizeof(oidC), country);
    AddNameRdn(nameRdns, oidE, sizeof(oidE), email);

    std::vector<unsigned char> nameContent;
    for (auto& rdn : nameRdns) nameContent.insert(nameContent.end(), rdn.begin(), rdn.end());
    auto subjectName = DerSequence({ nameContent });

    // Serial number (random 16 bytes)
    std::vector<unsigned char> serial(16);
    BCryptGenRandom(NULL, serial.data(), 16, BCRYPT_USE_SYSTEM_PREFERRED_RNG);

    // Validity
    SYSTEMTIME nowUtc;
    GetSystemTime(&nowUtc);

    SYSTEMTIME notAfter = nowUtc;
    notAfter.wYear += (WORD)validityYears;
    if (validityYears > 9999 - nowUtc.wYear) notAfter.wYear = 9999;

    auto validity = DerSequence({ DerUtcTime(nowUtc), DerUtcTime(notAfter) });

    // Extensions: Basic Constraints (CA:TRUE, critical) + Key Usage (keyCertSign + cRLSign, critical)
    // OID 2.5.29.19 = { 55, 1D, 13 }  Basic Constraints
    const unsigned char oidBasicConstraints[] = { 0x55, 0x1D, 0x13 };
    const unsigned char oidKeyUsage[] = { 0x55, 0x1D, 0x0F };

    // Basic Constraints: SEQUENCE { cA BOOLEAN TRUE, pathLenConstraint INTEGER 0 }
    auto bcValue = DerSequence({ DerBoolean(true), DerIntegerFromSize(0) });
    auto bcExt = DerSequence({
        DerOid(oidBasicConstraints, sizeof(oidBasicConstraints)),
        DerBoolean(true),
        DerOctetString(bcValue)
    });

    // Key Usage: keyCertSign (bit 5) + cRLSign (bit 6) = 0b01100000 = 0x60
    std::vector<unsigned char> kuBitStr;
    kuBitStr.push_back(0x03); // BIT STRING tag
    kuBitStr.push_back(0x02); // length = 2
    kuBitStr.push_back(0x01); // 1 unused bit (bit 7)
    kuBitStr.push_back(0x60); // 0b01100000

    auto kuExt = DerSequence({
        DerOid(oidKeyUsage, sizeof(oidKeyUsage)),
        DerBoolean(true),
        DerOctetString(kuBitStr)
    });

    auto extensions = DerSequence({ bcExt, kuExt });

    // Signature algorithm
    std::vector<unsigned char> sigAlgSeq;
    const unsigned char* hashAlgOid;
    size_t hashAlgOidLen;
    const unsigned char oidSha256[] = { 0x60, 0x86, 0x48, 0x01, 0x65, 0x03, 0x04, 0x02, 0x01 };
    const unsigned char oidSha384[] = { 0x60, 0x86, 0x48, 0x01, 0x65, 0x03, 0x04, 0x02, 0x02 };
    const unsigned char oidSha512[] = { 0x60, 0x86, 0x48, 0x01, 0x65, 0x03, 0x04, 0x02, 0x03 };

    if (isECC) {
        const unsigned char oidEcdsa[] = { 0x2A, 0x86, 0x48, 0xCE, 0x3D, 0x04, 0x01 };
        hashAlgOid = oidSha256; hashAlgOidLen = sizeof(oidSha256);
        if (keyIdx == 4) { hashAlgOid = oidSha384; hashAlgOidLen = sizeof(oidSha384); }
        if (keyIdx == 5) { hashAlgOid = oidSha512; hashAlgOidLen = sizeof(oidSha512); }
        sigAlgSeq = DerSequence({ DerOid(oidEcdsa, sizeof(oidEcdsa)), DerOid(hashAlgOid, hashAlgOidLen) });
    } else {
        const unsigned char oidSha256Rsa[] = { 0x2A, 0x86, 0x48, 0x86, 0xF7, 0x0D, 0x01, 0x01, 0x0B };
        sigAlgSeq = DerSequence({ DerOid(oidSha256Rsa, sizeof(oidSha256Rsa)) });
        hashAlgOid = oidSha256; hashAlgOidLen = sizeof(oidSha256);
    }

    // TBS Certificate
    // version [0] EXPLICIT INTEGER v3(2)
    auto version = DerExplicitTag(0, DerIntegerFromSize(2));

    auto tbsCert = DerSequence({
        version,
        DerInteger(serial),
        sigAlgSeq,
        subjectName,
        validity,
        subjectName,   // issuer = subject (self-signed)
        spki,
        DerExplicitTag(3, extensions)
    });

    // Hash and sign
    auto hash = Sha256Hash(tbsCert.data(), tbsCert.size());

    BCRYPT_PKCS1_PADDING_INFO padInfo = {};
    if (isECC) {
        if (keyIdx == 3) padInfo.pszAlgId = BCRYPT_SHA256_ALGORITHM;
        else if (keyIdx == 4) padInfo.pszAlgId = BCRYPT_SHA384_ALGORITHM;
        else padInfo.pszAlgId = BCRYPT_SHA512_ALGORITHM;
    } else {
        padInfo.pszAlgId = BCRYPT_SHA256_ALGORITHM;
    }

    DWORD signFlags = isECC ? 0 : BCRYPT_PAD_PKCS1;
    cb = 0;
    st = NCryptSignHash(hKey, &padInfo, hash.data(), (ULONG)hash.size(), NULL, 0, &cb, signFlags);
    if (!NT_SUCCESS(st)) { NCryptFreeObject(hKey); NCryptFreeObject(hProv); return false; }

    std::vector<unsigned char> sig(cb);
    st = NCryptSignHash(hKey, &padInfo, hash.data(), (ULONG)hash.size(), sig.data(), cb, &cb, signFlags);
    if (!NT_SUCCESS(st)) { NCryptFreeObject(hKey); NCryptFreeObject(hProv); return false; }

    // Full certificate
    auto cert = DerSequence({ tbsCert, sigAlgSeq, DerBitString(sig) });
    outCertPem = WrapPem(BytesToBase64(cert.data(), cert.size()), "CERTIFICATE");

    // Info
    std::ostringstream oss;
    oss << "=== CA Certificate (Self-Signed) ===\r\n\r\n";
    oss << "--- Certificate (PEM) ---\r\n" << outCertPem << "\r\n\r\n";
    oss << "--- Private Key (PEM) ---\r\n" << outPrivPem << "\r\n\r\n";
    oss << "--- Public Key (PEM) ---\r\n" << outPubPem << "\r\n\r\n";
    oss << "--- Details ---\r\n";
    oss << "Subject: " << WstringToUtf8(cn.empty() ? L"(none)" : cn);
    if (!org.empty()) oss << ", O=" << WstringToUtf8(org);
    if (!ou.empty()) oss << ", OU=" << WstringToUtf8(ou);
    if (!loc.empty()) oss << ", L=" << WstringToUtf8(loc);
    if (!state.empty()) oss << ", S=" << WstringToUtf8(state);
    if (!country.empty()) oss << ", C=" << WstringToUtf8(country);
    if (!email.empty()) oss << ", E=" << WstringToUtf8(email);
    oss << "\r\n";
    oss << "Algorithm: " << (isECC ? "ECDSA" : "RSA") << "\r\n";
    if (isECC) oss << "Curve: " << WstringToUtf8(ecCurve) << "\r\n";
    else oss << "Key Size: " << rsaBits << " bits\r\n";
    oss << "Validity: " << validityYears << " year" << (validityYears != 1 ? "s" : "") << "\r\n";
    oss << "CA: TRUE\r\n";
    oss << "Key Usage: keyCertSign, cRLSign\r\n";
    outInfo = oss.str();

    NCryptFreeObject(hKey);
    NCryptFreeObject(hProv);
    return true;
}

void HandleCACert(HWND hwnd) {
    CADlgCtx ctx = {};
    if (!OpenCADialog(hwnd, &ctx)) return;

    int validityYears = ctx.validityYears;
    if (validityYears < 1) validityYears = 1;
    if (validityYears > 9999) validityYears = 9999;

    std::string certPem, privPem, pubPem, info;
    if (!BuildCACert(ctx.cn, ctx.org, ctx.ou,
        ctx.loc, ctx.state, ctx.country, ctx.email,
        ctx.keyIdx, validityYears, certPem, privPem, pubPem, info)) {
        SetStatus(L"CA Certificate: Key generation or certificate creation failed.");
        return;
    }

    SetEditText(hOutputEdit, Utf8ToWstring(info));
    SetStatus(L"CA certificate created successfully.");
}

// ===== DER Cursor for parsing private keys =====
struct DerCursor {
    const unsigned char* data;
    size_t len;
    size_t pos;
    DerCursor(const unsigned char* d, size_t l) : data(d), len(l), pos(0) {}

    bool readTag(unsigned char& tag) {
        if (pos >= len) return false;
        tag = data[pos++];
        return true;
    }
    bool readLength(size_t& length) {
        if (pos >= len) return false;
        unsigned char b = data[pos++];
        if (b < 0x80) { length = b; return true; }
        int n = b & 0x7F;
        if (n > 4 || pos + n > len) return false;
        length = 0;
        for (int i = 0; i < n; i++) length = (length << 8) | data[pos++];
        return true;
    }
    bool skipContent() {
        size_t length;
        unsigned char tag;
        if (!readTag(tag)) return false;
        if (!readLength(length)) return false;
        if (pos + length > len) return false;
        pos += length;
        return true;
    }
    bool enterSequence() {
        unsigned char tag;
        if (!readTag(tag) || tag != 0x30) return false;
        size_t length;
        if (!readLength(length)) return false;
        if (pos + length > len) return false;
        return true;
    }
    bool readInteger(std::vector<unsigned char>& value) {
        unsigned char tag;
        if (!readTag(tag) || tag != 0x02) return false;
        size_t length;
        if (!readLength(length)) return false;
        if (pos + length > len) return false;
        size_t start = pos;
        while (length > 1 && data[start] == 0x00) { start++; length--; }
        value.assign(data + start, data + start + length);
        pos = start + length;
        return true;
    }
    bool readOctetString(std::vector<unsigned char>& value) {
        unsigned char tag;
        if (!readTag(tag) || tag != 0x04) return false;
        size_t length;
        if (!readLength(length)) return false;
        if (pos + length > len) return false;
        value.assign(data + pos, data + pos + length);
        pos += length;
        return true;
    }
    bool skipOptionalContext(int tagNum) {
        if (pos >= len) return true;
        unsigned char expectedTag = 0xA0 | (unsigned char)tagNum;
        if (data[pos] != expectedTag) return true;
        return skipContent();
    }
};

static std::string ReadFileToString(const std::wstring& path) {
    HANDLE hFile = CreateFileW(path.c_str(), GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
    if (hFile == INVALID_HANDLE_VALUE) return "";
    DWORD sz = GetFileSize(hFile, NULL);
    if (sz == INVALID_FILE_SIZE || sz == 0) { CloseHandle(hFile); return ""; }
    std::vector<char> buf(sz);
    DWORD br = 0;
    ReadFile(hFile, buf.data(), sz, &br, NULL);
    CloseHandle(hFile);
    return std::string(buf.begin(), buf.begin() + br);
}

static std::vector<unsigned char> PemToDer(const std::string& pem, const char* label) {
    std::string beginMark = "-----BEGIN ";
    beginMark += label;
    beginMark += "-----";
    std::string endMark = "-----END ";
    endMark += label;
    endMark += "-----";

    size_t begin = pem.find(beginMark);
    size_t end = pem.find(endMark, begin);
    if (begin == std::string::npos || end == std::string::npos) return {};
    begin += beginMark.size();
    std::string b64;
    for (size_t i = begin; i < end; i++) {
        if (!isspace((unsigned char)pem[i])) b64 += pem[i];
    }
    std::string decoded = base64_decode(b64);
    return std::vector<unsigned char>(decoded.begin(), decoded.end());
}

static bool ImportCaPrivateKey(const std::vector<unsigned char>& der,
    const wchar_t* certAlgo, NCRYPT_PROV_HANDLE hProv, NCRYPT_KEY_HANDLE& hKey)
{
    bool isECC = (wcsstr(certAlgo, L"ECDSA") != NULL);

    if (isECC) {
        DerCursor cur(der.data(), der.size());
        if (!cur.enterSequence()) return false;
        // Skip version INTEGER
        if (!cur.skipContent()) return false;
        // Read private key OCTET STRING
        std::vector<unsigned char> privKey;
        if (!cur.readOctetString(privKey)) return false;

        std::vector<BYTE> blob(sizeof(BCRYPT_ECCKEY_BLOB) + privKey.size());
        BCRYPT_ECCKEY_BLOB* hdr = (BCRYPT_ECCKEY_BLOB*)blob.data();
        hdr->dwMagic = BCRYPT_ECDSA_PRIVATE_GENERIC_MAGIC;
        hdr->cbKey = (DWORD)privKey.size();
        memcpy(blob.data() + sizeof(BCRYPT_ECCKEY_BLOB), privKey.data(), privKey.size());
        NTSTATUS st = NCryptImportKey(hProv, 0, BCRYPT_ECCPRIVATE_BLOB, NULL, &hKey, blob.data(), (DWORD)blob.size(), 0);
        return NT_SUCCESS(st);
    } else {
        DerCursor cur(der.data(), der.size());
        if (!cur.enterSequence()) return false;

        // Read 9 integers: version, modulus, pubExp, privExp, p, q, dp, dq, qinv
        std::vector<std::vector<unsigned char>> ints;
        for (int i = 0; i < 9; i++) {
            std::vector<unsigned char> v;
            if (!cur.readInteger(v)) return false;
            ints.push_back(v);
        }

        // Build BCRYPT_RSAKEY_BLOB (publicExp, modulus, prime1, prime2)
        std::vector<BYTE> blob(sizeof(BCRYPT_RSAKEY_BLOB) +
            ints[2].size() + ints[1].size() + ints[4].size() + ints[5].size());
        BCRYPT_RSAKEY_BLOB* hdr = (BCRYPT_RSAKEY_BLOB*)blob.data();
        hdr->Magic = BCRYPT_RSAPRIVATE_MAGIC;
        hdr->BitLength = (DWORD)(ints[1].size() * 8);
        hdr->cbPublicExp = (DWORD)ints[2].size();
        hdr->cbModulus = (DWORD)ints[1].size();
        hdr->cbPrime1 = (DWORD)ints[4].size();
        hdr->cbPrime2 = (DWORD)ints[5].size();

        BYTE* p = blob.data() + sizeof(BCRYPT_RSAKEY_BLOB);
        memcpy(p, ints[2].data(), ints[2].size()); p += ints[2].size();  // publicExp
        memcpy(p, ints[1].data(), ints[1].size()); p += ints[1].size();  // modulus
        memcpy(p, ints[4].data(), ints[4].size()); p += ints[4].size();  // prime1
        memcpy(p, ints[5].data(), ints[5].size()); p += ints[5].size();  // prime2

        NTSTATUS st = NCryptImportKey(hProv, 0, BCRYPT_RSAPRIVATE_BLOB, NULL, &hKey, blob.data(), (DWORD)blob.size(), 0);
        return NT_SUCCESS(st);
    }
}

// ===== CA-Signed Certificate =====
struct SignDlgCtx {
    HWND hCN, hOrg, hOU, hLoc, hState, hCountry, hEmail;
    HWND hKeyCombo, hValidityEdit;
    HWND hCACertEdit, hCAKeyEdit;
    bool confirmed;
    std::wstring cn, org, ou, loc, state, country, email;
    std::wstring caCertPath, caKeyPath;
    int keyIdx, validityYears;
};

static const wchar_t SIGN_DLG_CLASS[] = L"SignDialogClass";
static bool signDlgClassRegistered = false;

LRESULT CALLBACK SignDlgProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
    SignDlgCtx* ctx = NULL;
    if (msg == WM_NCCREATE) {
        ctx = (SignDlgCtx*)((CREATESTRUCTW*)lParam)->lpCreateParams;
        SetWindowLongPtr(hwnd, GWLP_USERDATA, (LONG_PTR)ctx);
        return DefWindowProcW(hwnd, msg, wParam, lParam);
    }
    ctx = (SignDlgCtx*)GetWindowLongPtr(hwnd, GWLP_USERDATA);
    if (!ctx) return DefWindowProcW(hwnd, msg, wParam, lParam);

    switch (msg) {
    case WM_CREATE: {
        HFONT hf = hBoldFont ? hBoldFont : (HFONT)GetStockObject(DEFAULT_GUI_FONT);
        HFONT hnf = hFont ? hFont : (HFONT)GetStockObject(SYSTEM_FONT);
        int y = 10;
        auto addLabel = [&](const wchar_t* text, int lblW) {
            HWND h = CreateWindowW(L"STATIC", text, WS_CHILD | WS_VISIBLE, 10, y + 3, lblW, 20, hwnd, NULL, NULL, NULL);
            SendMessage(h, WM_SETFONT, (WPARAM)hf, TRUE);
        };
        auto addEdit = [&](int id, int exW) {
            HWND h = CreateWindowExW(WS_EX_CLIENTEDGE, L"EDIT", L"",
                WS_CHILD | WS_VISIBLE | WS_TABSTOP, 10 + 140, y, exW, 23, hwnd, (HMENU)(INT_PTR)id, NULL, NULL);
            SendMessage(h, WM_SETFONT, (WPARAM)hnf, TRUE);
            return h;
        };

        addLabel(L"Common Name (CN):", 135); ctx->hCN = addEdit(IDC_SIGN_CN, 345); y += 28;
        addLabel(L"Organization (O):", 135); ctx->hOrg = addEdit(IDC_SIGN_ORG, 345); y += 28;
        addLabel(L"Org Unit (OU):", 135); ctx->hOU = addEdit(IDC_SIGN_OU, 345); y += 28;
        addLabel(L"Locality (L):", 135); ctx->hLoc = addEdit(IDC_SIGN_LOCALITY, 345); y += 28;
        addLabel(L"State (S):", 135); ctx->hState = addEdit(IDC_SIGN_STATE, 345); y += 28;
        addLabel(L"Country (C):", 135); ctx->hCountry = addEdit(IDC_SIGN_COUNTRY, 345); y += 28;
        addLabel(L"Email (E):", 135); ctx->hEmail = addEdit(IDC_SIGN_EMAIL, 345); y += 33;

        addLabel(L"Key Type:", 135);
        ctx->hKeyCombo = CreateWindowExW(0, L"COMBOBOX", L"",
            WS_CHILD | WS_VISIBLE | WS_TABSTOP | CBS_DROPDOWNLIST,
            10 + 140, y, 200, 200, hwnd, (HMENU)(INT_PTR)IDC_SIGN_KEYTYPE, NULL, NULL);
        SendMessage(ctx->hKeyCombo, WM_SETFONT, (WPARAM)hnf, TRUE);
        const wchar_t* keyTypes[] = { L"RSA 2048", L"RSA 3072", L"RSA 4096", L"ECDSA P-256", L"ECDSA P-384", L"ECDSA P-521" };
        for (auto& kt : keyTypes) SendMessageW(ctx->hKeyCombo, CB_ADDSTRING, 0, (LPARAM)kt);
        SendMessage(ctx->hKeyCombo, CB_SETCURSEL, 0, 0);
        y += 33;

        addLabel(L"Validity (years):", 135);
        ctx->hValidityEdit = CreateWindowExW(WS_EX_CLIENTEDGE, L"EDIT", L"1",
            WS_CHILD | WS_VISIBLE | WS_TABSTOP | ES_NUMBER,
            10 + 140, y, 60, 23, hwnd, (HMENU)(INT_PTR)IDC_SIGN_VALIDITY, NULL, NULL);
        SendMessage(ctx->hValidityEdit, WM_SETFONT, (WPARAM)hnf, TRUE);
        y += 33;

        addLabel(L"CA Certificate (.pem):", 135);
        ctx->hCACertEdit = CreateWindowExW(WS_EX_CLIENTEDGE, L"EDIT", L"",
            WS_CHILD | WS_VISIBLE | WS_TABSTOP, 10 + 140, y, 270, 23, hwnd, (HMENU)(INT_PTR)IDC_SIGN_CA_CERT, NULL, NULL);
        SendMessage(ctx->hCACertEdit, WM_SETFONT, (WPARAM)hnf, TRUE);
        HWND hBrowse1 = CreateWindowW(L"BUTTON", L"Browse...",
            WS_CHILD | WS_VISIBLE | WS_TABSTOP, 10 + 415, y, 75, 23, hwnd, (HMENU)(INT_PTR)IDC_SIGN_CA_CERT_BROWSE, NULL, NULL);
        SendMessage(hBrowse1, WM_SETFONT, (WPARAM)hf, TRUE);
        y += 30;

        addLabel(L"CA Private Key (.pem):", 135);
        ctx->hCAKeyEdit = CreateWindowExW(WS_EX_CLIENTEDGE, L"EDIT", L"",
            WS_CHILD | WS_VISIBLE | WS_TABSTOP, 10 + 140, y, 270, 23, hwnd, (HMENU)(INT_PTR)IDC_SIGN_CA_KEY, NULL, NULL);
        SendMessage(ctx->hCAKeyEdit, WM_SETFONT, (WPARAM)hnf, TRUE);
        HWND hBrowse2 = CreateWindowW(L"BUTTON", L"Browse...",
            WS_CHILD | WS_VISIBLE | WS_TABSTOP, 10 + 415, y, 75, 23, hwnd, (HMENU)(INT_PTR)IDC_SIGN_CA_KEY_BROWSE, NULL, NULL);
        SendMessage(hBrowse2, WM_SETFONT, (WPARAM)hf, TRUE);
        y += 38;

        HWND hBtn = CreateWindowW(L"BUTTON", L"Sign Certificate",
            WS_CHILD | WS_VISIBLE | WS_TABSTOP | BS_DEFPUSHBUTTON,
            10, y, 140, 30, hwnd, (HMENU)(INT_PTR)IDC_SIGN_GENERATE, NULL, NULL);
        SendMessage(hBtn, WM_SETFONT, (WPARAM)hf, TRUE);

        HWND hCancel = CreateWindowW(L"BUTTON", L"Cancel",
            WS_CHILD | WS_VISIBLE | WS_TABSTOP,
            160, y, 90, 30, hwnd, (HMENU)(INT_PTR)IDC_SIGN_CANCEL, NULL, NULL);
        SendMessage(hCancel, WM_SETFONT, (WPARAM)hf, TRUE);

        SetFocus(ctx->hCN);
        return 0;
    }
    case WM_COMMAND:
        if (ctx) {
            if (LOWORD(wParam) == IDC_SIGN_CA_CERT_BROWSE) {
                wchar_t fn[MAX_PATH] = L"";
                OPENFILENAMEW ofn = {}; ofn.lStructSize = sizeof(ofn);
                ofn.lpstrFilter = L"PEM Files (*.pem)\0*.pem\0All Files (*.*)\0*.*\0";
                ofn.lpstrFile = fn; ofn.nMaxFile = MAX_PATH;
                ofn.Flags = OFN_FILEMUSTEXIST | OFN_PATHMUSTEXIST;
                ofn.lpstrTitle = L"Select CA Certificate";
                if (GetOpenFileNameW(&ofn)) SetWindowTextW(ctx->hCACertEdit, fn);
                return 0;
            }
            if (LOWORD(wParam) == IDC_SIGN_CA_KEY_BROWSE) {
                wchar_t fn[MAX_PATH] = L"";
                OPENFILENAMEW ofn = {}; ofn.lStructSize = sizeof(ofn);
                ofn.lpstrFilter = L"PEM Files (*.pem)\0*.pem\0All Files (*.*)\0*.*\0";
                ofn.lpstrFile = fn; ofn.nMaxFile = MAX_PATH;
                ofn.Flags = OFN_FILEMUSTEXIST | OFN_PATHMUSTEXIST;
                ofn.lpstrTitle = L"Select CA Private Key";
                if (GetOpenFileNameW(&ofn)) SetWindowTextW(ctx->hCAKeyEdit, fn);
                return 0;
            }
            if (LOWORD(wParam) == IDC_SIGN_GENERATE) {
                ctx->cn = GetEditText(ctx->hCN);
                if (ctx->cn.empty()) { MessageBoxW(hwnd, L"Common Name (CN) is required.", L"CA-Signed Certificate", MB_ICONINFORMATION); SetFocus(ctx->hCN); return 0; }
                ctx->org = GetEditText(ctx->hOrg);
                ctx->ou = GetEditText(ctx->hOU);
                ctx->loc = GetEditText(ctx->hLoc);
                ctx->state = GetEditText(ctx->hState);
                ctx->country = GetEditText(ctx->hCountry);
                ctx->email = GetEditText(ctx->hEmail);
                ctx->keyIdx = (int)SendMessageW(ctx->hKeyCombo, CB_GETCURSEL, 0, 0);
                wchar_t vbuf[16] = {};
                GetWindowTextW(ctx->hValidityEdit, vbuf, 16);
                ctx->validityYears = _wtoi(vbuf);
                ctx->caCertPath.resize(MAX_PATH);
                GetWindowTextW(ctx->hCACertEdit, &ctx->caCertPath[0], MAX_PATH);
                ctx->caCertPath.resize(wcslen(ctx->caCertPath.c_str()));
                if (ctx->caCertPath.empty()) { MessageBoxW(hwnd, L"CA certificate file is required.", L"CA-Signed Certificate", MB_ICONINFORMATION); SetFocus(ctx->hCACertEdit); return 0; }
                ctx->caKeyPath.resize(MAX_PATH);
                GetWindowTextW(ctx->hCAKeyEdit, &ctx->caKeyPath[0], MAX_PATH);
                ctx->caKeyPath.resize(wcslen(ctx->caKeyPath.c_str()));
                if (ctx->caKeyPath.empty()) { MessageBoxW(hwnd, L"CA private key file is required.", L"CA-Signed Certificate", MB_ICONINFORMATION); SetFocus(ctx->hCAKeyEdit); return 0; }
                ctx->confirmed = true;
                DestroyWindow(hwnd);
                return 0;
            }
            if (LOWORD(wParam) == IDC_SIGN_CANCEL || LOWORD(wParam) == IDCANCEL) { DestroyWindow(hwnd); return 0; }
        }
        break;
    case WM_SIZE: {
        RECT rc; GetClientRect(hwnd, &rc);
        int cw = rc.right, ch = rc.bottom;
        HWND hChild = GetWindow(hwnd, GW_CHILD);
        int bottomY = ch - 40;
        while (hChild) {
            HWND hNext = GetWindow(hChild, GW_HWNDNEXT);
            wchar_t cls[32] = {};
            GetClassNameW(hChild, cls, 32);
            RECT cr = {}; GetWindowRect(hChild, &cr);
            ScreenToClient(hwnd, (POINT*)&cr);
            int origY = cr.top, origX = cr.left;
            int origW = cr.right - cr.left, origH = cr.bottom - cr.top;
            if (wcscmp(cls, L"BUTTON") == 0) {
                if (origX > 400) {
                    int newBtnX = cw - origW - 12;
                    MoveWindow(hChild, newBtnX, origY, origW, origH, TRUE);
                } else {
                    MoveWindow(hChild, origX, bottomY, origW, origH, TRUE);
                }
            } else if (wcscmp(cls, L"EDIT") == 0 || wcscmp(cls, L"COMBOBOX") == 0) {
                int newW;
                if (origX > 400) {
                    newW = cw - origX - 12;
                } else {
                    newW = cw - origX - 12;
                }
                if (newW < 80) newW = 80;
                MoveWindow(hChild, origX, origY, newW, origH, TRUE);
            }
            hChild = hNext;
        }
        break;
    }
    case WM_CLOSE: DestroyWindow(hwnd); return 0;
    }
    return DefWindowProcW(hwnd, msg, wParam, lParam);
}

bool OpenSignDialog(HWND parent, SignDlgCtx* ctx) {
    if (!signDlgClassRegistered) {
        WNDCLASSEXW wc = {};
        wc.cbSize = sizeof(wc);
        wc.lpfnWndProc = SignDlgProc;
        wc.hInstance = g_hInstance;
        wc.hCursor = LoadCursor(NULL, IDC_ARROW);
        wc.hbrBackground = (HBRUSH)(COLOR_BTNFACE + 1);
        wc.lpszClassName = SIGN_DLG_CLASS;
        RegisterClassExW(&wc);
        signDlgClassRegistered = true;
    }
    int screenW = GetSystemMetrics(SM_CXSCREEN);
    int screenH = GetSystemMetrics(SM_CYSCREEN);
    int dlgW = 680, dlgH = 470;
    HWND hDlg = CreateWindowExW(WS_EX_DLGMODALFRAME | WS_EX_TOPMOST,
        SIGN_DLG_CLASS, L"Create CA-Signed Certificate",
        WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU | WS_THICKFRAME | WS_MAXIMIZEBOX,
        (screenW - dlgW) / 2, (screenH - dlgH) / 2, dlgW, dlgH,
        parent, NULL, g_hInstance, ctx);
    if (!hDlg) return false;
    EnableWindow(parent, FALSE);
    ShowWindow(hDlg, SW_SHOW);
    MSG msg;
    while (IsWindow(hDlg)) {
        BOOL ret = GetMessageW(&msg, NULL, 0, 0);
        if (ret == 0 || ret == -1) break;
        if (!IsWindow(hDlg)) break;
        if (!IsDialogMessageW(hDlg, &msg)) { TranslateMessage(&msg); DispatchMessageW(&msg); }
    }
    EnableWindow(parent, TRUE);
    SetForegroundWindow(parent);
    return ctx->confirmed;
}

static bool BuildSignedCert(
    const std::wstring& cn, const std::wstring& org, const std::wstring& ou,
    const std::wstring& loc, const std::wstring& state, const std::wstring& country,
    const std::wstring& email, int keyIdx, int validityYears,
    const std::wstring& caCertPath, const std::wstring& caKeyPath,
    std::string& outCertPem, std::string& outPrivPem, std::string& outInfo)
{
    // Load CA certificate
    std::string caCertPemStr = ReadFileToString(caCertPath);
    if (caCertPemStr.empty()) { outInfo = "Failed to read CA certificate file."; return false; }
    auto caCertDer = PemToDer(caCertPemStr, "CERTIFICATE");
    if (caCertDer.empty()) { outInfo = "Failed to parse CA certificate PEM."; return false; }

    PCCERT_CONTEXT pCACert = CertCreateCertificateContext(
        X509_ASN_ENCODING | PKCS_7_ASN_ENCODING, caCertDer.data(), (DWORD)caCertDer.size());
    if (!pCACert) { outInfo = "Failed to decode CA certificate. Error " + std::to_string(GetLastError()); return false; }

    // Get issuer name (for subject of signed cert) and signature algorithm from CA cert
    DWORD issuerSize = CertNameToStrA(X509_ASN_ENCODING | PKCS_7_ASN_ENCODING,
        &pCACert->pCertInfo->Issuer, CERT_SIMPLE_NAME_STR, NULL, 0);
    std::vector<char> issuerName(issuerSize);
    CertNameToStrA(X509_ASN_ENCODING | PKCS_7_ASN_ENCODING,
        &pCACert->pCertInfo->Issuer, CERT_SIMPLE_NAME_STR, issuerName.data(), issuerSize);

    // Detect CA key type from CA cert's public key algorithm OID
    LPSTR algoOid = pCACert->pCertInfo->SubjectPublicKeyInfo.Algorithm.pszObjId;
    bool caIsECC = (strcmp(algoOid, "1.2.840.10045.2.1") == 0);

    // Load CA private key
    std::string caKeyPemStr = ReadFileToString(caKeyPath);
    if (caKeyPemStr.empty()) { CertFreeCertificateContext(pCACert); outInfo = "Failed to read CA private key file."; return false; }

    std::vector<unsigned char> caKeyDer;
    if (caIsECC)
        caKeyDer = PemToDer(caKeyPemStr, "EC PRIVATE KEY");
    else
        caKeyDer = PemToDer(caKeyPemStr, "RSA PRIVATE KEY");
    if (caKeyDer.empty()) caKeyDer = PemToDer(caKeyPemStr, "PRIVATE KEY"); // PKCS#8 fallback
    if (caKeyDer.empty()) { CertFreeCertificateContext(pCACert); outInfo = "Failed to parse CA private key PEM."; return false; }

    NCRYPT_PROV_HANDLE hProv = 0;
    NCRYPT_KEY_HANDLE hCAKey = 0;
    NTSTATUS st = NCryptOpenStorageProvider(&hProv, MS_KEY_STORAGE_PROVIDER, 0);
    if (!NT_SUCCESS(st)) { CertFreeCertificateContext(pCACert); outInfo = "Failed to open NCrypt provider."; return false; }

    if (!ImportCaPrivateKey(caKeyDer, caIsECC ? L"ECDSA" : L"RSA", hProv, hCAKey)) {
        // For PKCS#8 wrapped keys, try parsing the outer sequence to find the inner key
        CertFreeCertificateContext(pCACert);
        NCryptFreeObject(hProv);
        outInfo = "Failed to import CA private key. Ensure the key matches the certificate.";
        return false;
    }

    // Generate new key pair for the signed certificate
    const wchar_t* ncryptAlgo = BCRYPT_RSA_ALGORITHM;
    const wchar_t* ecCurve = NULL;
    int rsaBits = 2048;
    bool isECC = false;

    switch (keyIdx) {
    case 0: rsaBits = 2048; break;
    case 1: rsaBits = 3072; break;
    case 2: rsaBits = 4096; break;
    case 3: ncryptAlgo = BCRYPT_ECDSA_ALGORITHM; ecCurve = BCRYPT_ECC_CURVE_NISTP256; isECC = true; break;
    case 4: ncryptAlgo = BCRYPT_ECDSA_ALGORITHM; ecCurve = BCRYPT_ECC_CURVE_NISTP384; isECC = true; break;
    case 5: ncryptAlgo = BCRYPT_ECDSA_ALGORITHM; ecCurve = BCRYPT_ECC_CURVE_NISTP521; isECC = true; break;
    }

    NCRYPT_KEY_HANDLE hNewKey = 0;
    st = NCryptCreatePersistedKey(hProv, &hNewKey, ncryptAlgo, NULL, 0, 0);
    if (!NT_SUCCESS(st)) { NCryptFreeObject(hCAKey); NCryptFreeObject(hProv); CertFreeCertificateContext(pCACert); return false; }

    if (isECC) {
        st = NCryptSetProperty(hNewKey, NCRYPT_ECC_CURVE_NAME_PROPERTY, (PBYTE)ecCurve,
            (DWORD)((wcslen(ecCurve) + 1) * sizeof(wchar_t)), 0);
    } else {
        st = NCryptSetProperty(hNewKey, NCRYPT_LENGTH_PROPERTY, (PBYTE)&rsaBits, sizeof(rsaBits), 0);
    }
    if (!NT_SUCCESS(st)) { NCryptFreeObject(hNewKey); NCryptFreeObject(hCAKey); NCryptFreeObject(hProv); CertFreeCertificateContext(pCACert); return false; }

    DWORD ep = NCRYPT_ALLOW_PLAINTEXT_EXPORT_FLAG | NCRYPT_ALLOW_EXPORT_FLAG;
    NCryptSetProperty(hNewKey, NCRYPT_EXPORT_POLICY_PROPERTY, (PBYTE)&ep, sizeof(ep), 0);
    st = NCryptFinalizeKey(hNewKey, 0);
    if (!NT_SUCCESS(st)) { NCryptFreeObject(hNewKey); NCryptFreeObject(hCAKey); NCryptFreeObject(hProv); CertFreeCertificateContext(pCACert); return false; }

    // Export new private key
    const wchar_t* privBlobType = isECC ? BCRYPT_ECCPRIVATE_BLOB : BCRYPT_RSAPRIVATE_BLOB;
    DWORD cb = 0;
    NCryptExportKey(hNewKey, 0, privBlobType, NULL, NULL, 0, &cb, 0);
    std::vector<unsigned char> privBlob(cb);
    NCryptExportKey(hNewKey, 0, privBlobType, NULL, privBlob.data(), cb, &cb, 0);
    outPrivPem = WrapPem(BytesToBase64(privBlob.data(), privBlob.size()),
        isECC ? "EC PRIVATE KEY" : "RSA PRIVATE KEY");

    // Export new public key and build SPKI
    const wchar_t* pubBlobType = isECC ? BCRYPT_ECCPUBLIC_BLOB : BCRYPT_RSAPUBLIC_BLOB;
    cb = 0;
    NCryptExportKey(hNewKey, 0, pubBlobType, NULL, NULL, 0, &cb, 0);
    std::vector<unsigned char> pubBlob(cb);
    NCryptExportKey(hNewKey, 0, pubBlobType, NULL, pubBlob.data(), cb, &cb, 0);

    std::vector<unsigned char> spki;
    if (isECC) {
        const unsigned char oidEcPubKey[] = { 0x2A, 0x86, 0x48, 0xCE, 0x3D, 0x02, 0x01 };
        std::vector<unsigned char> curveOid;
        if (wcscmp(ecCurve, BCRYPT_ECC_CURVE_NISTP256) == 0)
            curveOid = { 0x2A, 0x86, 0x48, 0xCE, 0x3D, 0x03, 0x01, 0x07 };
        else if (wcscmp(ecCurve, BCRYPT_ECC_CURVE_NISTP384) == 0)
            curveOid = { 0x2B, 0x81, 0x04, 0x00, 0x22 };
        else
            curveOid = { 0x2B, 0x81, 0x04, 0x00, 0x23 };

        auto algId = DerSequence({ DerOid(oidEcPubKey, sizeof(oidEcPubKey)), DerOid(curveOid.data(), curveOid.size()) });
        DWORD keySize = 32;
        if (wcscmp(ecCurve, BCRYPT_ECC_CURVE_NISTP384) == 0) keySize = 48;
        else if (wcscmp(ecCurve, BCRYPT_ECC_CURVE_NISTP521) == 0) keySize = 66;

        std::vector<unsigned char> point;
        point.push_back(0x04);
        BYTE* x = pubBlob.data() + sizeof(BCRYPT_ECCKEY_BLOB);
        BYTE* y = x + keySize;
        point.insert(point.end(), x, x + keySize);
        point.insert(point.end(), y, y + keySize);
        spki = DerSequence({ algId, DerBitString(point) });
    } else {
        const unsigned char oidRsa[] = { 0x2A, 0x86, 0x48, 0x86, 0xF7, 0x0D, 0x01, 0x01, 0x01 };
        BCRYPT_RSAKEY_BLOB* rsaBlob = (BCRYPT_RSAKEY_BLOB*)pubBlob.data();
        BYTE* modulus = pubBlob.data() + sizeof(BCRYPT_RSAKEY_BLOB);
        BYTE* exp = modulus + rsaBlob->cbModulus;
        auto algId = DerSequence({ DerOid(oidRsa, sizeof(oidRsa)) });
        auto rsaPubKey = DerSequence({
            DerInteger(std::vector<unsigned char>(modulus, modulus + rsaBlob->cbModulus)),
            DerInteger(std::vector<unsigned char>(exp, exp + rsaBlob->cbPublicExp))
        });
        spki = DerSequence({ algId, DerBitString(rsaPubKey) });
    }

    // Build subject name
    std::vector<std::vector<unsigned char>> nameRdns;
    AddNameRdn(nameRdns, oidCN, sizeof(oidCN), cn);
    AddNameRdn(nameRdns, oidO, sizeof(oidO), org);
    AddNameRdn(nameRdns, oidOU, sizeof(oidOU), ou);
    AddNameRdn(nameRdns, oidL, sizeof(oidL), loc);
    AddNameRdn(nameRdns, oidS, sizeof(oidS), state);
    AddNameRdn(nameRdns, oidC, sizeof(oidC), country);
    AddNameRdn(nameRdns, oidE, sizeof(oidE), email);

    std::vector<unsigned char> nameContent;
    for (auto& rdn : nameRdns) nameContent.insert(nameContent.end(), rdn.begin(), rdn.end());
    auto subjectName = DerSequence({ nameContent });

    // Serial number
    std::vector<unsigned char> serial(16);
    BCryptGenRandom(NULL, serial.data(), 16, BCRYPT_USE_SYSTEM_PREFERRED_RNG);

    // Validity
    SYSTEMTIME nowUtc;
    GetSystemTime(&nowUtc);
    SYSTEMTIME notAfter = nowUtc;
    notAfter.wYear += (WORD)validityYears;
    if (validityYears > 9999 - nowUtc.wYear) notAfter.wYear = 9999;
    auto validity = DerSequence({ DerUtcTime(nowUtc), DerUtcTime(notAfter) });

    // Extensions: Basic Constraints (CA:FALSE) + Key Usage
    const unsigned char oidBasicConstraints[] = { 0x55, 0x1D, 0x13 };
    const unsigned char oidKeyUsage[] = { 0x55, 0x1D, 0x0F };

    auto bcValue = DerSequence({ DerBoolean(false) });
    auto bcExt = DerSequence({
        DerOid(oidBasicConstraints, sizeof(oidBasicConstraints)),
        DerBoolean(false),
        DerOctetString(bcValue)
    });

    std::vector<unsigned char> kuBitStr;
    kuBitStr.push_back(0x03); // BIT STRING tag
    if (isECC) {
        kuBitStr.push_back(0x02); // length = 2
        kuBitStr.push_back(0x06); // 6 unused bits
        kuBitStr.push_back(0x80); // digitalSignature = bit 0 = 0x80
    } else {
        kuBitStr.push_back(0x02); // length = 2
        kuBitStr.push_back(0x05); // 5 unused bits
        kuBitStr.push_back(0xA0); // digitalSignature (bit 0) + keyEncipherment (bit 2) = 0b10100000
    }

    auto kuExt = DerSequence({
        DerOid(oidKeyUsage, sizeof(oidKeyUsage)),
        DerBoolean(true),
        DerOctetString(kuBitStr)
    });

    auto extensions = DerSequence({ bcExt, kuExt });

    // Signature algorithm (match CA cert's algorithm)
    std::vector<unsigned char> sigAlgSeq;
    const unsigned char oidSha256[] = { 0x60, 0x86, 0x48, 0x01, 0x65, 0x03, 0x04, 0x02, 0x01 };
    const unsigned char oidSha384[] = { 0x60, 0x86, 0x48, 0x01, 0x65, 0x03, 0x04, 0x02, 0x02 };
    const unsigned char oidSha512[] = { 0x60, 0x86, 0x48, 0x01, 0x65, 0x03, 0x04, 0x02, 0x03 };

    const unsigned char* hashAlgOid = oidSha256;
    size_t hashAlgOidLen = sizeof(oidSha256);
    if (caIsECC) {
        const unsigned char oidEcdsa[] = { 0x2A, 0x86, 0x48, 0xCE, 0x3D, 0x04, 0x01 };
        sigAlgSeq = DerSequence({ DerOid(oidEcdsa, sizeof(oidEcdsa)), DerOid(hashAlgOid, hashAlgOidLen) });
    } else {
        const unsigned char oidSha256Rsa[] = { 0x2A, 0x86, 0x48, 0x86, 0xF7, 0x0D, 0x01, 0x01, 0x0B };
        sigAlgSeq = DerSequence({ DerOid(oidSha256Rsa, sizeof(oidSha256Rsa)) });
    }

    // TBS Certificate
    auto version = DerExplicitTag(0, DerIntegerFromSize(2));
    CRYPT_DATA_BLOB issuerBlob = pCACert->pCertInfo->Issuer;
    std::vector<unsigned char> issuerDer(issuerBlob.pbData, issuerBlob.pbData + issuerBlob.cbData);
    auto tbsCert = DerSequence({
        version,
        DerInteger(serial),
        sigAlgSeq,
        issuerDer,  // issuer = CA's subject
        validity,
        subjectName,
        spki,
        DerExplicitTag(3, extensions)
    });

    // Hash and sign with CA key
    auto hash = Sha256Hash(tbsCert.data(), tbsCert.size());

    BCRYPT_PKCS1_PADDING_INFO padInfo = {};
    if (caIsECC) {
        padInfo.pszAlgId = BCRYPT_SHA256_ALGORITHM;
    } else {
        padInfo.pszAlgId = BCRYPT_SHA256_ALGORITHM;
    }

    DWORD signFlags = caIsECC ? 0 : BCRYPT_PAD_PKCS1;
    cb = 0;
    st = NCryptSignHash(hCAKey, &padInfo, hash.data(), (ULONG)hash.size(), NULL, 0, &cb, signFlags);
    if (!NT_SUCCESS(st)) {
        NCryptFreeObject(hNewKey); NCryptFreeObject(hCAKey); NCryptFreeObject(hProv);
        CertFreeCertificateContext(pCACert);
        outInfo = "Failed to sign with CA key. Error " + std::to_string(st);
        return false;
    }

    std::vector<unsigned char> sig(cb);
    st = NCryptSignHash(hCAKey, &padInfo, hash.data(), (ULONG)hash.size(), sig.data(), cb, &cb, signFlags);
    if (!NT_SUCCESS(st)) {
        NCryptFreeObject(hNewKey); NCryptFreeObject(hCAKey); NCryptFreeObject(hProv);
        CertFreeCertificateContext(pCACert);
        outInfo = "Failed to sign with CA key. Error " + std::to_string(st);
        return false;
    }

    // Build certificate
    auto cert = DerSequence({ tbsCert, sigAlgSeq, DerBitString(sig) });
    outCertPem = WrapPem(BytesToBase64(cert.data(), cert.size()), "CERTIFICATE");

    // Info
    std::ostringstream oss;
    oss << "=== CA-Signed Certificate ===\r\n\r\n";
    oss << "--- Certificate (PEM) ---\r\n" << outCertPem << "\r\n\r\n";
    oss << "--- Private Key (PEM) ---\r\n" << outPrivPem << "\r\n\r\n";
    oss << "--- Details ---\r\n";
    oss << "Subject: " << WstringToUtf8(cn.empty() ? L"(none)" : cn);
    if (!org.empty()) oss << ", O=" << WstringToUtf8(org);
    if (!ou.empty()) oss << ", OU=" << WstringToUtf8(ou);
    if (!loc.empty()) oss << ", L=" << WstringToUtf8(loc);
    if (!state.empty()) oss << ", S=" << WstringToUtf8(state);
    if (!country.empty()) oss << ", C=" << WstringToUtf8(country);
    if (!email.empty()) oss << ", E=" << WstringToUtf8(email);
    oss << "\r\n";
    oss << "Issuer: " << issuerName.data() << "\r\n";
    oss << "Algorithm: " << (isECC ? "ECDSA" : "RSA") << "\r\n";
    if (isECC) oss << "Curve: " << WstringToUtf8(ecCurve) << "\r\n";
    else oss << "Key Size: " << rsaBits << " bits\r\n";
    oss << "Validity: " << validityYears << " year" << (validityYears != 1 ? "s" : "") << "\r\n";
    oss << "CA: FALSE\r\n";
    outInfo = oss.str();

    NCryptFreeObject(hNewKey);
    NCryptFreeObject(hCAKey);
    NCryptFreeObject(hProv);
    CertFreeCertificateContext(pCACert);
    return true;
}

void HandleSignCert(HWND hwnd) {
    SignDlgCtx ctx = {};
    if (!OpenSignDialog(hwnd, &ctx)) return;

    int validityYears = ctx.validityYears;
    if (validityYears < 1) validityYears = 1;
    if (validityYears > 9999) validityYears = 9999;

    std::string certPem, privPem, info;
    if (!BuildSignedCert(ctx.cn, ctx.org, ctx.ou, ctx.loc, ctx.state, ctx.country, ctx.email,
        ctx.keyIdx, validityYears, ctx.caCertPath, ctx.caKeyPath,
        certPem, privPem, info)) {
        SetStatus(L"CA-Signed Cert: " + Utf8ToWstring(info));
        return;
    }

    SetEditText(hOutputEdit, Utf8ToWstring(info));
    SetStatus(L"CA-signed certificate created successfully.");
}

// ===== TLS / Server / User Certificate =====
enum TlsCertType { TLS_TYPE_TLS = 0, TLS_TYPE_SERVER = 1, TLS_TYPE_USER = 2 };

struct TlsDlgCtx {
    HWND hTypeCombo;
    HWND hCN, hOrg, hOU, hLoc, hState, hCountry, hEmail;
    HWND hSanEdit;
    HWND hKeyCombo, hValidityEdit;
    HWND hCACertEdit, hCAKeyEdit;
    bool confirmed;
    int certType, keyIdx, validityYears, initialCertType;
    std::wstring cn, org, ou, loc, state, country, email, san;
    std::wstring caCertPath, caKeyPath;
};

static const wchar_t TLS_DLG_CLASS[] = L"TlsDialogClass";
static bool tlsDlgClassRegistered = false;

LRESULT CALLBACK TlsDlgProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
    TlsDlgCtx* ctx = NULL;
    if (msg == WM_NCCREATE) {
        ctx = (TlsDlgCtx*)((CREATESTRUCTW*)lParam)->lpCreateParams;
        SetWindowLongPtr(hwnd, GWLP_USERDATA, (LONG_PTR)ctx);
        return DefWindowProcW(hwnd, msg, wParam, lParam);
    }
    ctx = (TlsDlgCtx*)GetWindowLongPtr(hwnd, GWLP_USERDATA);
    if (!ctx) return DefWindowProcW(hwnd, msg, wParam, lParam);

    switch (msg) {
    case WM_CREATE: {
        HFONT hf = hBoldFont ? hBoldFont : (HFONT)GetStockObject(DEFAULT_GUI_FONT);
        HFONT hnf = hFont ? hFont : (HFONT)GetStockObject(SYSTEM_FONT);
        int y = 10;
        auto addLabel = [&](const wchar_t* text, int lblW) {
            HWND h = CreateWindowW(L"STATIC", text, WS_CHILD | WS_VISIBLE, 10, y + 3, lblW, 20, hwnd, NULL, NULL, NULL);
            SendMessage(h, WM_SETFONT, (WPARAM)hf, TRUE);
        };
        auto addEdit = [&](int id, int exW) {
            HWND h = CreateWindowExW(WS_EX_CLIENTEDGE, L"EDIT", L"",
                WS_CHILD | WS_VISIBLE | WS_TABSTOP, 10 + 140, y, exW, 23, hwnd, (HMENU)(INT_PTR)id, NULL, NULL);
            SendMessage(h, WM_SETFONT, (WPARAM)hnf, TRUE);
            return h;
        };

        addLabel(L"Certificate Type:", 135);
        ctx->hTypeCombo = CreateWindowExW(0, L"COMBOBOX", L"",
            WS_CHILD | WS_VISIBLE | WS_TABSTOP | CBS_DROPDOWNLIST,
            10 + 140, y, 250, 200, hwnd, (HMENU)(INT_PTR)IDC_TLS_TYPE, NULL, NULL);
        SendMessage(ctx->hTypeCombo, WM_SETFONT, (WPARAM)hf, TRUE);
        SendMessageW(ctx->hTypeCombo, CB_ADDSTRING, 0, (LPARAM)L"TLS Certificate (Server + SAN)");
        SendMessageW(ctx->hTypeCombo, CB_ADDSTRING, 0, (LPARAM)L"Server Certificate");
        SendMessageW(ctx->hTypeCombo, CB_ADDSTRING, 0, (LPARAM)L"User Certificate (Client)");
        SendMessage(ctx->hTypeCombo, CB_SETCURSEL, ctx->initialCertType, 0);
        y += 33;

        addLabel(L"Common Name (CN):", 135); ctx->hCN = addEdit(IDC_TLS_CN, 345); y += 28;
        addLabel(L"Organization (O):", 135); ctx->hOrg = addEdit(IDC_TLS_ORG, 345); y += 28;
        addLabel(L"Org Unit (OU):", 135); ctx->hOU = addEdit(IDC_TLS_OU, 345); y += 28;
        addLabel(L"Locality (L):", 135); ctx->hLoc = addEdit(IDC_TLS_LOCALITY, 345); y += 28;
        addLabel(L"State (S):", 135); ctx->hState = addEdit(IDC_TLS_STATE, 345); y += 28;
        addLabel(L"Country (C):", 135); ctx->hCountry = addEdit(IDC_TLS_COUNTRY, 345); y += 28;
        addLabel(L"Email (E):", 135); ctx->hEmail = addEdit(IDC_TLS_EMAIL, 345); y += 28;

        addLabel(L"Subject Alt Names:", 135);
        ctx->hSanEdit = CreateWindowExW(WS_EX_CLIENTEDGE, L"EDIT", L"",
            WS_CHILD | WS_VISIBLE | WS_TABSTOP, 10 + 140, y, 345, 23, hwnd, (HMENU)(INT_PTR)IDC_TLS_SAN, NULL, NULL);
        SendMessage(ctx->hSanEdit, WM_SETFONT, (WPARAM)hnf, TRUE);
        y += 28;

        HWND hSanHint = CreateWindowW(L"STATIC",
            L"Comma-separated DNS names: example.com, www.example.com",
            WS_CHILD | WS_VISIBLE, 10 + 140, y, 345, 16, hwnd, NULL, NULL, NULL);
        SendMessage(hSanHint, WM_SETFONT, (WPARAM)hnf, TRUE);
        y += 22;

        addLabel(L"Key Type:", 135);
        ctx->hKeyCombo = CreateWindowExW(0, L"COMBOBOX", L"",
            WS_CHILD | WS_VISIBLE | WS_TABSTOP | CBS_DROPDOWNLIST,
            10 + 140, y, 200, 200, hwnd, (HMENU)(INT_PTR)IDC_TLS_KEYTYPE, NULL, NULL);
        SendMessage(ctx->hKeyCombo, WM_SETFONT, (WPARAM)hf, TRUE);
        const wchar_t* keyTypes[] = { L"RSA 2048", L"RSA 3072", L"RSA 4096", L"ECDSA P-256", L"ECDSA P-384", L"ECDSA P-521" };
        for (auto& kt : keyTypes) SendMessageW(ctx->hKeyCombo, CB_ADDSTRING, 0, (LPARAM)kt);
        SendMessage(ctx->hKeyCombo, CB_SETCURSEL, 0, 0);
        y += 33;

        addLabel(L"Validity (years):", 135);
        ctx->hValidityEdit = CreateWindowExW(WS_EX_CLIENTEDGE, L"EDIT", L"1",
            WS_CHILD | WS_VISIBLE | WS_TABSTOP | ES_NUMBER,
            10 + 140, y, 60, 23, hwnd, (HMENU)(INT_PTR)IDC_TLS_VALIDITY, NULL, NULL);
        SendMessage(ctx->hValidityEdit, WM_SETFONT, (WPARAM)hnf, TRUE);
        y += 33;

        addLabel(L"CA Certificate (.pem):", 135);
        ctx->hCACertEdit = CreateWindowExW(WS_EX_CLIENTEDGE, L"EDIT", L"",
            WS_CHILD | WS_VISIBLE | WS_TABSTOP, 10 + 140, y, 270, 23, hwnd, (HMENU)(INT_PTR)IDC_TLS_CA_CERT, NULL, NULL);
        SendMessage(ctx->hCACertEdit, WM_SETFONT, (WPARAM)hnf, TRUE);
        HWND hBrowse1 = CreateWindowW(L"BUTTON", L"Browse...",
            WS_CHILD | WS_VISIBLE | WS_TABSTOP, 10 + 415, y, 75, 23, hwnd, (HMENU)(INT_PTR)IDC_TLS_CA_CERT_BROWSE, NULL, NULL);
        SendMessage(hBrowse1, WM_SETFONT, (WPARAM)hf, TRUE);
        y += 30;

        addLabel(L"CA Private Key (.pem):", 135);
        ctx->hCAKeyEdit = CreateWindowExW(WS_EX_CLIENTEDGE, L"EDIT", L"",
            WS_CHILD | WS_VISIBLE | WS_TABSTOP, 10 + 140, y, 270, 23, hwnd, (HMENU)(INT_PTR)IDC_TLS_CA_KEY, NULL, NULL);
        SendMessage(ctx->hCAKeyEdit, WM_SETFONT, (WPARAM)hnf, TRUE);
        HWND hBrowse2 = CreateWindowW(L"BUTTON", L"Browse...",
            WS_CHILD | WS_VISIBLE | WS_TABSTOP, 10 + 415, y, 75, 23, hwnd, (HMENU)(INT_PTR)IDC_TLS_CA_KEY_BROWSE, NULL, NULL);
        SendMessage(hBrowse2, WM_SETFONT, (WPARAM)hf, TRUE);
        y += 38;

        HWND hBtn = CreateWindowW(L"BUTTON", L"Create Certificate",
            WS_CHILD | WS_VISIBLE | WS_TABSTOP | BS_DEFPUSHBUTTON,
            10, y, 140, 30, hwnd, (HMENU)(INT_PTR)IDC_TLS_GENERATE, NULL, NULL);
        SendMessage(hBtn, WM_SETFONT, (WPARAM)hf, TRUE);

        HWND hCancel = CreateWindowW(L"BUTTON", L"Cancel",
            WS_CHILD | WS_VISIBLE | WS_TABSTOP,
            160, y, 90, 30, hwnd, (HMENU)(INT_PTR)IDC_TLS_CANCEL, NULL, NULL);
        SendMessage(hCancel, WM_SETFONT, (WPARAM)hf, TRUE);

        SetFocus(ctx->hCN);
        return 0;
    }
    case WM_COMMAND:
        if (ctx) {
            if (LOWORD(wParam) == IDC_TLS_CA_CERT_BROWSE) {
                wchar_t fn[MAX_PATH] = L"";
                OPENFILENAMEW ofn = {}; ofn.lStructSize = sizeof(ofn);
                ofn.lpstrFilter = L"PEM Files (*.pem)\0*.pem\0All Files (*.*)\0*.*\0";
                ofn.lpstrFile = fn; ofn.nMaxFile = MAX_PATH;
                ofn.Flags = OFN_FILEMUSTEXIST | OFN_PATHMUSTEXIST;
                ofn.lpstrTitle = L"Select CA Certificate";
                if (GetOpenFileNameW(&ofn)) SetWindowTextW(ctx->hCACertEdit, fn);
                return 0;
            }
            if (LOWORD(wParam) == IDC_TLS_CA_KEY_BROWSE) {
                wchar_t fn[MAX_PATH] = L"";
                OPENFILENAMEW ofn = {}; ofn.lStructSize = sizeof(ofn);
                ofn.lpstrFilter = L"PEM Files (*.pem)\0*.pem\0All Files (*.*)\0*.*\0";
                ofn.lpstrFile = fn; ofn.nMaxFile = MAX_PATH;
                ofn.Flags = OFN_FILEMUSTEXIST | OFN_PATHMUSTEXIST;
                ofn.lpstrTitle = L"Select CA Private Key";
                if (GetOpenFileNameW(&ofn)) SetWindowTextW(ctx->hCAKeyEdit, fn);
                return 0;
            }
            if (LOWORD(wParam) == IDC_TLS_GENERATE) {
                ctx->certType = (int)SendMessageW(ctx->hTypeCombo, CB_GETCURSEL, 0, 0);
                ctx->cn = GetEditText(ctx->hCN);
                if (ctx->cn.empty()) { MessageBoxW(hwnd, L"Common Name (CN) is required.", L"Certificate", MB_ICONINFORMATION); SetFocus(ctx->hCN); return 0; }
                ctx->org = GetEditText(ctx->hOrg);
                ctx->ou = GetEditText(ctx->hOU);
                ctx->loc = GetEditText(ctx->hLoc);
                ctx->state = GetEditText(ctx->hState);
                ctx->country = GetEditText(ctx->hCountry);
                ctx->email = GetEditText(ctx->hEmail);
                ctx->san = GetEditText(ctx->hSanEdit);
                if (ctx->certType == TLS_TYPE_TLS && ctx->san.empty()) {
                    MessageBoxW(hwnd, L"At least one Subject Alt Name (DNS) is required for TLS certificates.", L"TLS Certificate", MB_ICONINFORMATION); SetFocus(ctx->hSanEdit); return 0;
                }
                ctx->keyIdx = (int)SendMessageW(ctx->hKeyCombo, CB_GETCURSEL, 0, 0);
                wchar_t vbuf[16] = {};
                GetWindowTextW(ctx->hValidityEdit, vbuf, 16);
                ctx->validityYears = _wtoi(vbuf);
                ctx->caCertPath.resize(MAX_PATH);
                GetWindowTextW(ctx->hCACertEdit, &ctx->caCertPath[0], MAX_PATH);
                ctx->caCertPath.resize(wcslen(ctx->caCertPath.c_str()));
                if (ctx->caCertPath.empty()) { MessageBoxW(hwnd, L"CA certificate file is required.", L"Certificate", MB_ICONINFORMATION); SetFocus(ctx->hCACertEdit); return 0; }
                ctx->caKeyPath.resize(MAX_PATH);
                GetWindowTextW(ctx->hCAKeyEdit, &ctx->caKeyPath[0], MAX_PATH);
                ctx->caKeyPath.resize(wcslen(ctx->caKeyPath.c_str()));
                if (ctx->caKeyPath.empty()) { MessageBoxW(hwnd, L"CA private key file is required.", L"Certificate", MB_ICONINFORMATION); SetFocus(ctx->hCAKeyEdit); return 0; }
                ctx->confirmed = true;
                DestroyWindow(hwnd);
                return 0;
            }
            if (LOWORD(wParam) == IDC_TLS_CANCEL || LOWORD(wParam) == IDCANCEL) { DestroyWindow(hwnd); return 0; }
        }
        break;
    case WM_SIZE: {
        RECT rc; GetClientRect(hwnd, &rc);
        int cw = rc.right, ch = rc.bottom;
        HWND hChild = GetWindow(hwnd, GW_CHILD);
        int bottomY = ch - 40;
        while (hChild) {
            HWND hNext = GetWindow(hChild, GW_HWNDNEXT);
            wchar_t cls[32] = {};
            GetClassNameW(hChild, cls, 32);
            RECT cr = {}; GetWindowRect(hChild, &cr);
            ScreenToClient(hwnd, (POINT*)&cr);
            int origY = cr.top, origX = cr.left, origW = cr.right - cr.left, origH = cr.bottom - cr.top;
            if (wcscmp(cls, L"BUTTON") == 0) {
                if (origX > 400) {
                    int newBtnX = cw - origW - 12;
                    MoveWindow(hChild, newBtnX, origY, origW, origH, TRUE);
                } else {
                    MoveWindow(hChild, origX, bottomY, origW, origH, TRUE);
                }
            } else if (wcscmp(cls, L"EDIT") == 0 || wcscmp(cls, L"COMBOBOX") == 0) {
                int newW = cw - origX - 12;
                if (newW < 80) newW = 80;
                MoveWindow(hChild, origX, origY, newW, origH, TRUE);
            }
            hChild = hNext;
        }
        break;
    }
    case WM_CLOSE: DestroyWindow(hwnd); return 0;
    }
    return DefWindowProcW(hwnd, msg, wParam, lParam);
}

bool OpenTlsDialog(HWND parent, TlsDlgCtx* ctx) {
    if (!tlsDlgClassRegistered) {
        WNDCLASSEXW wc = {};
        wc.cbSize = sizeof(wc);
        wc.lpfnWndProc = TlsDlgProc;
        wc.hInstance = g_hInstance;
        wc.hCursor = LoadCursor(NULL, IDC_ARROW);
        wc.hbrBackground = (HBRUSH)(COLOR_BTNFACE + 1);
        wc.lpszClassName = TLS_DLG_CLASS;
        RegisterClassExW(&wc);
        tlsDlgClassRegistered = true;
    }
    int screenW = GetSystemMetrics(SM_CXSCREEN);
    int screenH = GetSystemMetrics(SM_CYSCREEN);
    int dlgW = 680, dlgH = 530;
    HWND hDlg = CreateWindowExW(WS_EX_DLGMODALFRAME | WS_EX_TOPMOST,
        TLS_DLG_CLASS, L"Create TLS / Server / User Certificate",
        WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU | WS_THICKFRAME | WS_MAXIMIZEBOX,
        (screenW - dlgW) / 2, (screenH - dlgH) / 2, dlgW, dlgH,
        parent, NULL, g_hInstance, ctx);
    if (!hDlg) return false;
    EnableWindow(parent, FALSE);
    ShowWindow(hDlg, SW_SHOW);
    MSG msg;
    while (IsWindow(hDlg)) {
        BOOL ret = GetMessageW(&msg, NULL, 0, 0);
        if (ret == 0 || ret == -1) break;
        if (!IsWindow(hDlg)) break;
        if (!IsDialogMessageW(hDlg, &msg)) { TranslateMessage(&msg); DispatchMessageW(&msg); }
    }
    EnableWindow(parent, TRUE);
    SetForegroundWindow(parent);
    return ctx->confirmed;
}

static std::vector<std::string> SplitSanEntries(const std::wstring& sanW) {
    std::vector<std::string> result;
    std::string san = WstringToUtf8(sanW);
    size_t pos = 0;
    while (pos < san.size()) {
        size_t comma = san.find(',', pos);
        std::string entry;
        if (comma == std::string::npos) { entry = san.substr(pos); pos = san.size(); }
        else { entry = san.substr(pos, comma - pos); pos = comma + 1; }
        while (!entry.empty() && entry[0] == ' ') entry.erase(0, 1);
        while (!entry.empty() && entry.back() == ' ') entry.pop_back();
        if (!entry.empty()) result.push_back(entry);
    }
    return result;
}

static bool BuildTlsCert(
    int certType, const std::wstring& cn, const std::wstring& org, const std::wstring& ou,
    const std::wstring& loc, const std::wstring& state, const std::wstring& country,
    const std::wstring& email, const std::wstring& san, int keyIdx, int validityYears,
    const std::wstring& caCertPath, const std::wstring& caKeyPath,
    std::string& outCertPem, std::string& outPrivPem, std::string& outInfo)
{
    // Load CA certificate
    std::string caCertPemStr = ReadFileToString(caCertPath);
    if (caCertPemStr.empty()) { outInfo = "Failed to read CA certificate file."; return false; }
    auto caCertDer = PemToDer(caCertPemStr, "CERTIFICATE");
    if (caCertDer.empty()) { outInfo = "Failed to parse CA certificate PEM."; return false; }

    PCCERT_CONTEXT pCACert = CertCreateCertificateContext(
        X509_ASN_ENCODING | PKCS_7_ASN_ENCODING, caCertDer.data(), (DWORD)caCertDer.size());
    if (!pCACert) { outInfo = "Failed to decode CA certificate. Error " + std::to_string(GetLastError()); return false; }

    // Get issuer name
    DWORD issuerSize = CertNameToStrA(X509_ASN_ENCODING | PKCS_7_ASN_ENCODING,
        &pCACert->pCertInfo->Issuer, CERT_SIMPLE_NAME_STR, NULL, 0);
    std::vector<char> issuerName(issuerSize);
    CertNameToStrA(X509_ASN_ENCODING | PKCS_7_ASN_ENCODING,
        &pCACert->pCertInfo->Issuer, CERT_SIMPLE_NAME_STR, issuerName.data(), issuerSize);

    LPSTR algoOid = pCACert->pCertInfo->SubjectPublicKeyInfo.Algorithm.pszObjId;
    bool caIsECC = (strcmp(algoOid, "1.2.840.10045.2.1") == 0);

    // Load CA private key
    std::string caKeyPemStr = ReadFileToString(caKeyPath);
    if (caKeyPemStr.empty()) { CertFreeCertificateContext(pCACert); outInfo = "Failed to read CA private key file."; return false; }

    std::vector<unsigned char> caKeyDer;
    if (caIsECC) caKeyDer = PemToDer(caKeyPemStr, "EC PRIVATE KEY");
    else caKeyDer = PemToDer(caKeyPemStr, "RSA PRIVATE KEY");
    if (caKeyDer.empty()) caKeyDer = PemToDer(caKeyPemStr, "PRIVATE KEY");
    if (caKeyDer.empty()) { CertFreeCertificateContext(pCACert); outInfo = "Failed to parse CA private key PEM."; return false; }

    NCRYPT_PROV_HANDLE hProv = 0;
    NCRYPT_KEY_HANDLE hCAKey = 0;
    NTSTATUS st = NCryptOpenStorageProvider(&hProv, MS_KEY_STORAGE_PROVIDER, 0);
    if (!NT_SUCCESS(st)) { CertFreeCertificateContext(pCACert); outInfo = "Failed to open NCrypt provider."; return false; }

    if (!ImportCaPrivateKey(caKeyDer, caIsECC ? L"ECDSA" : L"RSA", hProv, hCAKey)) {
        CertFreeCertificateContext(pCACert); NCryptFreeObject(hProv);
        outInfo = "Failed to import CA private key."; return false;
    }

    // Generate new key pair
    const wchar_t* ncryptAlgo = BCRYPT_RSA_ALGORITHM;
    const wchar_t* ecCurve = NULL;
    int rsaBits = 2048;
    bool isECC = false;
    switch (keyIdx) {
    case 0: rsaBits = 2048; break;
    case 1: rsaBits = 3072; break;
    case 2: rsaBits = 4096; break;
    case 3: ncryptAlgo = BCRYPT_ECDSA_ALGORITHM; ecCurve = BCRYPT_ECC_CURVE_NISTP256; isECC = true; break;
    case 4: ncryptAlgo = BCRYPT_ECDSA_ALGORITHM; ecCurve = BCRYPT_ECC_CURVE_NISTP384; isECC = true; break;
    case 5: ncryptAlgo = BCRYPT_ECDSA_ALGORITHM; ecCurve = BCRYPT_ECC_CURVE_NISTP521; isECC = true; break;
    }

    NCRYPT_KEY_HANDLE hNewKey = 0;
    st = NCryptCreatePersistedKey(hProv, &hNewKey, ncryptAlgo, NULL, 0, 0);
    if (!NT_SUCCESS(st)) { NCryptFreeObject(hCAKey); NCryptFreeObject(hProv); CertFreeCertificateContext(pCACert); return false; }

    if (isECC) {
        st = NCryptSetProperty(hNewKey, NCRYPT_ECC_CURVE_NAME_PROPERTY, (PBYTE)ecCurve,
            (DWORD)((wcslen(ecCurve) + 1) * sizeof(wchar_t)), 0);
    } else {
        st = NCryptSetProperty(hNewKey, NCRYPT_LENGTH_PROPERTY, (PBYTE)&rsaBits, sizeof(rsaBits), 0);
    }
    if (!NT_SUCCESS(st)) { NCryptFreeObject(hNewKey); NCryptFreeObject(hCAKey); NCryptFreeObject(hProv); CertFreeCertificateContext(pCACert); return false; }

    DWORD ep = NCRYPT_ALLOW_PLAINTEXT_EXPORT_FLAG | NCRYPT_ALLOW_EXPORT_FLAG;
    NCryptSetProperty(hNewKey, NCRYPT_EXPORT_POLICY_PROPERTY, (PBYTE)&ep, sizeof(ep), 0);
    st = NCryptFinalizeKey(hNewKey, 0);
    if (!NT_SUCCESS(st)) { NCryptFreeObject(hNewKey); NCryptFreeObject(hCAKey); NCryptFreeObject(hProv); CertFreeCertificateContext(pCACert); return false; }

    // Export new private key
    const wchar_t* privBlobType = isECC ? BCRYPT_ECCPRIVATE_BLOB : BCRYPT_RSAPRIVATE_BLOB;
    DWORD cb = 0;
    NCryptExportKey(hNewKey, 0, privBlobType, NULL, NULL, 0, &cb, 0);
    std::vector<unsigned char> privBlob(cb);
    NCryptExportKey(hNewKey, 0, privBlobType, NULL, privBlob.data(), cb, &cb, 0);
    outPrivPem = WrapPem(BytesToBase64(privBlob.data(), privBlob.size()),
        isECC ? "EC PRIVATE KEY" : "RSA PRIVATE KEY");

    // Export new public key and build SPKI
    const wchar_t* pubBlobType = isECC ? BCRYPT_ECCPUBLIC_BLOB : BCRYPT_RSAPUBLIC_BLOB;
    cb = 0;
    NCryptExportKey(hNewKey, 0, pubBlobType, NULL, NULL, 0, &cb, 0);
    std::vector<unsigned char> pubBlob(cb);
    NCryptExportKey(hNewKey, 0, pubBlobType, NULL, pubBlob.data(), cb, &cb, 0);

    std::vector<unsigned char> spki;
    if (isECC) {
        const unsigned char oidEcPubKey[] = { 0x2A, 0x86, 0x48, 0xCE, 0x3D, 0x02, 0x01 };
        std::vector<unsigned char> curveOid;
        if (wcscmp(ecCurve, BCRYPT_ECC_CURVE_NISTP256) == 0) curveOid = { 0x2A, 0x86, 0x48, 0xCE, 0x3D, 0x03, 0x01, 0x07 };
        else if (wcscmp(ecCurve, BCRYPT_ECC_CURVE_NISTP384) == 0) curveOid = { 0x2B, 0x81, 0x04, 0x00, 0x22 };
        else curveOid = { 0x2B, 0x81, 0x04, 0x00, 0x23 };
        auto algId = DerSequence({ DerOid(oidEcPubKey, sizeof(oidEcPubKey)), DerOid(curveOid.data(), curveOid.size()) });
        DWORD keySize = 32;
        if (wcscmp(ecCurve, BCRYPT_ECC_CURVE_NISTP384) == 0) keySize = 48;
        else if (wcscmp(ecCurve, BCRYPT_ECC_CURVE_NISTP521) == 0) keySize = 66;
        std::vector<unsigned char> point;
        point.push_back(0x04);
        BYTE* x = pubBlob.data() + sizeof(BCRYPT_ECCKEY_BLOB);
        BYTE* y = x + keySize;
        point.insert(point.end(), x, x + keySize);
        point.insert(point.end(), y, y + keySize);
        spki = DerSequence({ algId, DerBitString(point) });
    } else {
        const unsigned char oidRsa[] = { 0x2A, 0x86, 0x48, 0x86, 0xF7, 0x0D, 0x01, 0x01, 0x01 };
        BCRYPT_RSAKEY_BLOB* rsaBlob = (BCRYPT_RSAKEY_BLOB*)pubBlob.data();
        BYTE* modulus = pubBlob.data() + sizeof(BCRYPT_RSAKEY_BLOB);
        BYTE* exp = modulus + rsaBlob->cbModulus;
        auto algId = DerSequence({ DerOid(oidRsa, sizeof(oidRsa)) });
        auto rsaPubKey = DerSequence({
            DerInteger(std::vector<unsigned char>(modulus, modulus + rsaBlob->cbModulus)),
            DerInteger(std::vector<unsigned char>(exp, exp + rsaBlob->cbPublicExp))
        });
        spki = DerSequence({ algId, DerBitString(rsaPubKey) });
    }

    // Build subject name
    std::vector<std::vector<unsigned char>> nameRdns;
    AddNameRdn(nameRdns, oidCN, sizeof(oidCN), cn);
    AddNameRdn(nameRdns, oidO, sizeof(oidO), org);
    AddNameRdn(nameRdns, oidOU, sizeof(oidOU), ou);
    AddNameRdn(nameRdns, oidL, sizeof(oidL), loc);
    AddNameRdn(nameRdns, oidS, sizeof(oidS), state);
    AddNameRdn(nameRdns, oidC, sizeof(oidC), country);
    AddNameRdn(nameRdns, oidE, sizeof(oidE), email);

    std::vector<unsigned char> nameContent;
    for (auto& rdn : nameRdns) nameContent.insert(nameContent.end(), rdn.begin(), rdn.end());
    auto subjectName = DerSequence({ nameContent });

    // Serial number
    std::vector<unsigned char> serial(16);
    BCryptGenRandom(NULL, serial.data(), 16, BCRYPT_USE_SYSTEM_PREFERRED_RNG);

    // Validity
    SYSTEMTIME nowUtc;
    GetSystemTime(&nowUtc);
    SYSTEMTIME notAfter = nowUtc;
    notAfter.wYear += (WORD)validityYears;
    if (validityYears > 9999 - nowUtc.wYear) notAfter.wYear = 9999;
    auto validity = DerSequence({ DerUtcTime(nowUtc), DerUtcTime(notAfter) });

    // Build extensions based on cert type
    // OID 2.5.29.19 = Basic Constraints
    // OID 2.5.29.15 = Key Usage
    // OID 2.5.29.37 = Extended Key Usage
    // OID 2.5.29.17 = Subject Alternative Name
    const unsigned char oidBC[] = { 0x55, 0x1D, 0x13 };
    const unsigned char oidKU[] = { 0x55, 0x1D, 0x0F };
    const unsigned char oidEKU[] = { 0x55, 0x1D, 0x25 };
    const unsigned char oidSAN[] = { 0x55, 0x1D, 0x11 };

    // Server Auth: 1.3.6.1.5.5.7.3.1
    const unsigned char oidServerAuth[] = { 0x2B, 0x06, 0x01, 0x05, 0x05, 0x07, 0x03, 0x01 };
    // Client Auth: 1.3.6.1.5.5.7.3.2
    const unsigned char oidClientAuth[] = { 0x2B, 0x06, 0x01, 0x05, 0x05, 0x07, 0x03, 0x02 };

    std::vector<std::vector<unsigned char>> exts;

    // Basic Constraints: CA:FALSE
    auto bcValue = DerSequence({ DerBoolean(false) });
    exts.push_back(DerSequence({ DerOid(oidBC, sizeof(oidBC)), DerBoolean(false), DerOctetString(bcValue) }));

    // Key Usage
    std::vector<unsigned char> kuBitStr;
    kuBitStr.push_back(0x03); // BIT STRING tag
    if (certType == TLS_TYPE_USER) {
        kuBitStr.push_back(0x02); // length = 2
        kuBitStr.push_back(0x06); // 6 unused bits
        kuBitStr.push_back(0x80); // digitalSignature = bit 0
    } else {
        kuBitStr.push_back(0x02); // length = 2
        kuBitStr.push_back(0x05); // 5 unused bits
        kuBitStr.push_back(0xA0); // digitalSignature (bit 0) + keyEncipherment (bit 2) = 0b10100000
    }
    exts.push_back(DerSequence({ DerOid(oidKU, sizeof(oidKU)), DerBoolean(true), DerOctetString(kuBitStr) }));

    // Extended Key Usage
    if (certType == TLS_TYPE_USER) {
        auto ekuValue = DerSequence({ DerOid(oidClientAuth, sizeof(oidClientAuth)) });
        exts.push_back(DerSequence({ DerOid(oidEKU, sizeof(oidEKU)), DerOctetString(ekuValue) }));
    } else {
        auto ekuValue = DerSequence({ DerOid(oidServerAuth, sizeof(oidServerAuth)) });
        exts.push_back(DerSequence({ DerOid(oidEKU, sizeof(oidEKU)), DerOctetString(ekuValue) }));
    }

    // Subject Alternative Name (for TLS and Server types)
    if (certType != TLS_TYPE_USER) {
        auto sanEntries = SplitSanEntries(san);
        if (sanEntries.empty() && certType == TLS_TYPE_TLS) {
            NCryptFreeObject(hNewKey); NCryptFreeObject(hCAKey); NCryptFreeObject(hProv);
            CertFreeCertificateContext(pCACert);
            outInfo = "TLS certificates require at least one Subject Alt Name (DNS name).";
            return false;
        }
        if (!sanEntries.empty()) {
            std::vector<std::vector<unsigned char>> sanItems;
            for (auto& entry : sanEntries) {
                // [2] EXPLICIT IA5String (DNS name)
                auto dnsName = DerWrap(0xA2, DerIA5String(entry));
                sanItems.push_back(dnsName);
            }
            std::vector<unsigned char> sanContent;
            for (auto& item : sanItems) sanContent.insert(sanContent.end(), item.begin(), item.end());
            auto sanSeq = DerSequence({ sanContent });
            // Wrap in another SEQUENCE for the SEQUENCE OF GeneralName
            std::vector<std::vector<unsigned char>> sanSeqVec = { sanContent };
            auto sanValue = DerSequence(sanSeqVec);
            exts.push_back(DerSequence({ DerOid(oidSAN, sizeof(oidSAN)), DerOctetString(sanValue) }));
        }
    }

    auto extensions = DerSequence(exts);

    // Signature algorithm
    std::vector<unsigned char> sigAlgSeq;
    const unsigned char oidSha256[] = { 0x60, 0x86, 0x48, 0x01, 0x65, 0x03, 0x04, 0x02, 0x01 };
    if (caIsECC) {
        const unsigned char oidEcdsa[] = { 0x2A, 0x86, 0x48, 0xCE, 0x3D, 0x04, 0x01 };
        sigAlgSeq = DerSequence({ DerOid(oidEcdsa, sizeof(oidEcdsa)), DerOid(oidSha256, sizeof(oidSha256)) });
    } else {
        const unsigned char oidSha256Rsa[] = { 0x2A, 0x86, 0x48, 0x86, 0xF7, 0x0D, 0x01, 0x01, 0x0B };
        sigAlgSeq = DerSequence({ DerOid(oidSha256Rsa, sizeof(oidSha256Rsa)) });
    }

    // TBS Certificate
    auto version = DerExplicitTag(0, DerIntegerFromSize(2));
    CRYPT_DATA_BLOB issuerBlob = pCACert->pCertInfo->Issuer;
    std::vector<unsigned char> issuerDer(issuerBlob.pbData, issuerBlob.pbData + issuerBlob.cbData);
    auto tbsCert = DerSequence({
        version, DerInteger(serial), sigAlgSeq,
        issuerDer, validity, subjectName, spki,
        DerExplicitTag(3, extensions)
    });

    // Sign with CA key
    auto hash = Sha256Hash(tbsCert.data(), tbsCert.size());
    BCRYPT_PKCS1_PADDING_INFO padInfo = {};
    padInfo.pszAlgId = BCRYPT_SHA256_ALGORITHM;
    DWORD signFlags = caIsECC ? 0 : BCRYPT_PAD_PKCS1;
    cb = 0;
    st = NCryptSignHash(hCAKey, &padInfo, hash.data(), (ULONG)hash.size(), NULL, 0, &cb, signFlags);
    if (!NT_SUCCESS(st)) {
        NCryptFreeObject(hNewKey); NCryptFreeObject(hCAKey); NCryptFreeObject(hProv);
        CertFreeCertificateContext(pCACert);
        outInfo = "Failed to sign with CA key. Error " + std::to_string(st);
        return false;
    }
    std::vector<unsigned char> sig(cb);
    st = NCryptSignHash(hCAKey, &padInfo, hash.data(), (ULONG)hash.size(), sig.data(), cb, &cb, signFlags);
    if (!NT_SUCCESS(st)) {
        NCryptFreeObject(hNewKey); NCryptFreeObject(hCAKey); NCryptFreeObject(hProv);
        CertFreeCertificateContext(pCACert);
        outInfo = "Failed to sign with CA key. Error " + std::to_string(st);
        return false;
    }

    auto cert = DerSequence({ tbsCert, sigAlgSeq, DerBitString(sig) });
    outCertPem = WrapPem(BytesToBase64(cert.data(), cert.size()), "CERTIFICATE");

    // Info
    const wchar_t* typeNames[] = { L"TLS Certificate", L"Server Certificate", L"User Certificate" };
    std::ostringstream oss;
    oss << "=== " << WstringToUtf8(typeNames[certType]) << " ===\r\n\r\n";
    oss << "--- Certificate (PEM) ---\r\n" << outCertPem << "\r\n\r\n";
    oss << "--- Private Key (PEM) ---\r\n" << outPrivPem << "\r\n\r\n";
    oss << "--- Details ---\r\n";
    oss << "Type: " << WstringToUtf8(typeNames[certType]) << "\r\n";
    oss << "Subject: " << WstringToUtf8(cn.empty() ? L"(none)" : cn);
    if (!org.empty()) oss << ", O=" << WstringToUtf8(org);
    if (!ou.empty()) oss << ", OU=" << WstringToUtf8(ou);
    if (!loc.empty()) oss << ", L=" << WstringToUtf8(loc);
    if (!state.empty()) oss << ", S=" << WstringToUtf8(state);
    if (!country.empty()) oss << ", C=" << WstringToUtf8(country);
    if (!email.empty()) oss << ", E=" << WstringToUtf8(email);
    oss << "\r\nIssuer: " << issuerName.data() << "\r\n";
    oss << "Algorithm: " << (isECC ? "ECDSA" : "RSA") << "\r\n";
    if (isECC) oss << "Curve: " << WstringToUtf8(ecCurve) << "\r\n";
    else oss << "Key Size: " << rsaBits << " bits\r\n";
    oss << "Validity: " << validityYears << " year" << (validityYears != 1 ? "s" : "") << "\r\n";
    oss << "Key Usage: digitalSignature";
    if (certType != TLS_TYPE_USER) oss << ", keyEncipherment";
    oss << "\r\n";
    oss << "Extended Key Usage: " << (certType == TLS_TYPE_USER ? "Client Authentication" : "Server Authentication") << "\r\n";
    if (!san.empty() && certType != TLS_TYPE_USER) oss << "SAN: " << WstringToUtf8(san) << "\r\n";
    outInfo = oss.str();

    NCryptFreeObject(hNewKey);
    NCryptFreeObject(hCAKey);
    NCryptFreeObject(hProv);
    CertFreeCertificateContext(pCACert);
    return true;
}

struct SelfCertDlgCtx {
    HWND hTypeCombo;
    HWND hCN, hOrg, hOU, hLoc, hState, hCountry, hEmail;
    HWND hSanEdit;
    HWND hKeyCombo, hValidityEdit;
    bool confirmed;
    int certType, keyIdx, validityYears;
    std::wstring cn, org, ou, loc, state, country, email, san;
};

static const wchar_t SELF_DLG_CLASS[] = L"SelfCertDialogClass";
static bool selfDlgClassRegistered = false;

LRESULT CALLBACK SelfCertDlgProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
    SelfCertDlgCtx* ctx = NULL;
    if (msg == WM_NCCREATE) {
        ctx = (SelfCertDlgCtx*)((CREATESTRUCTW*)lParam)->lpCreateParams;
        SetWindowLongPtr(hwnd, GWLP_USERDATA, (LONG_PTR)ctx);
        return DefWindowProcW(hwnd, msg, wParam, lParam);
    }
    ctx = (SelfCertDlgCtx*)GetWindowLongPtr(hwnd, GWLP_USERDATA);
    if (!ctx) return DefWindowProcW(hwnd, msg, wParam, lParam);

    switch (msg) {
    case WM_CREATE: {
        HFONT hf = hBoldFont ? hBoldFont : (HFONT)GetStockObject(DEFAULT_GUI_FONT);
        HFONT hnf = hFont ? hFont : (HFONT)GetStockObject(SYSTEM_FONT);
        int y = 10;
        auto addLabel = [&](const wchar_t* text, int lblW) {
            HWND h = CreateWindowW(L"STATIC", text, WS_CHILD | WS_VISIBLE, 10, y + 3, lblW, 20, hwnd, NULL, NULL, NULL);
            SendMessage(h, WM_SETFONT, (WPARAM)hf, TRUE);
        };
        auto addEdit = [&](int id, int exW) {
            HWND h = CreateWindowExW(WS_EX_CLIENTEDGE, L"EDIT", L"",
                WS_CHILD | WS_VISIBLE | WS_TABSTOP, 10 + 140, y, exW, 23, hwnd, (HMENU)(INT_PTR)id, NULL, NULL);
            SendMessage(h, WM_SETFONT, (WPARAM)hnf, TRUE);
            return h;
        };

        addLabel(L"Certificate Type:", 135);
        ctx->hTypeCombo = CreateWindowExW(0, L"COMBOBOX", L"",
            WS_CHILD | WS_VISIBLE | WS_TABSTOP | CBS_DROPDOWNLIST,
            10 + 140, y, 250, 200, hwnd, (HMENU)(INT_PTR)IDC_SELF_TYPE, NULL, NULL);
        SendMessage(ctx->hTypeCombo, WM_SETFONT, (WPARAM)hf, TRUE);
        SendMessageW(ctx->hTypeCombo, CB_ADDSTRING, 0, (LPARAM)L"TLS Certificate (Server + SAN)");
        SendMessageW(ctx->hTypeCombo, CB_ADDSTRING, 0, (LPARAM)L"Server Certificate");
        SendMessageW(ctx->hTypeCombo, CB_ADDSTRING, 0, (LPARAM)L"User Certificate (Client)");
        SendMessage(ctx->hTypeCombo, CB_SETCURSEL, ctx->certType, 0);
        y += 33;

        addLabel(L"Common Name (CN):", 135); ctx->hCN = addEdit(IDC_SELF_CN, 345); y += 28;
        addLabel(L"Organization (O):", 135); ctx->hOrg = addEdit(IDC_SELF_ORG, 345); y += 28;
        addLabel(L"Org Unit (OU):", 135); ctx->hOU = addEdit(IDC_SELF_OU, 345); y += 28;
        addLabel(L"Locality (L):", 135); ctx->hLoc = addEdit(IDC_SELF_LOCALITY, 345); y += 28;
        addLabel(L"State (S):", 135); ctx->hState = addEdit(IDC_SELF_STATE, 345); y += 28;
        addLabel(L"Country (C):", 135); ctx->hCountry = addEdit(IDC_SELF_COUNTRY, 345); y += 28;
        addLabel(L"Email (E):", 135); ctx->hEmail = addEdit(IDC_SELF_EMAIL, 345); y += 28;

        addLabel(L"Subject Alt Names:", 135);
        ctx->hSanEdit = CreateWindowExW(WS_EX_CLIENTEDGE, L"EDIT", L"",
            WS_CHILD | WS_VISIBLE | WS_TABSTOP, 10 + 140, y, 345, 23, hwnd, (HMENU)(INT_PTR)IDC_SELF_SAN, NULL, NULL);
        SendMessage(ctx->hSanEdit, WM_SETFONT, (WPARAM)hnf, TRUE);
        y += 28;

        HWND hSanHint = CreateWindowW(L"STATIC",
            L"Comma-separated DNS names (required for TLS type): example.com, www.example.com",
            WS_CHILD | WS_VISIBLE, 10 + 140, y, 400, 16, hwnd, NULL, NULL, NULL);
        SendMessage(hSanHint, WM_SETFONT, (WPARAM)hnf, TRUE);
        y += 22;

        addLabel(L"Key Type:", 135);
        ctx->hKeyCombo = CreateWindowExW(0, L"COMBOBOX", L"",
            WS_CHILD | WS_VISIBLE | WS_TABSTOP | CBS_DROPDOWNLIST,
            10 + 140, y, 200, 200, hwnd, (HMENU)(INT_PTR)IDC_SELF_KEYTYPE, NULL, NULL);
        SendMessage(ctx->hKeyCombo, WM_SETFONT, (WPARAM)hf, TRUE);
        const wchar_t* keyTypes[] = { L"RSA 2048", L"RSA 3072", L"RSA 4096", L"ECDSA P-256", L"ECDSA P-384", L"ECDSA P-521" };
        for (auto& kt : keyTypes) SendMessageW(ctx->hKeyCombo, CB_ADDSTRING, 0, (LPARAM)kt);
        SendMessage(ctx->hKeyCombo, CB_SETCURSEL, 0, 0);
        y += 33;

        addLabel(L"Validity (years):", 135);
        ctx->hValidityEdit = CreateWindowExW(WS_EX_CLIENTEDGE, L"EDIT", L"1",
            WS_CHILD | WS_VISIBLE | WS_TABSTOP | ES_NUMBER,
            10 + 140, y, 60, 23, hwnd, (HMENU)(INT_PTR)IDC_SELF_VALIDITY, NULL, NULL);
        SendMessage(ctx->hValidityEdit, WM_SETFONT, (WPARAM)hnf, TRUE);
        y += 38;

        HWND hBtn = CreateWindowW(L"BUTTON", L"Create Self-Signed Certificate",
            WS_CHILD | WS_VISIBLE | WS_TABSTOP | BS_DEFPUSHBUTTON,
            10, y, 200, 30, hwnd, (HMENU)(INT_PTR)IDC_SELF_GENERATE, NULL, NULL);
        SendMessage(hBtn, WM_SETFONT, (WPARAM)hf, TRUE);

        HWND hCancel = CreateWindowW(L"BUTTON", L"Cancel",
            WS_CHILD | WS_VISIBLE | WS_TABSTOP,
            220, y, 90, 30, hwnd, (HMENU)(INT_PTR)IDC_SELF_CANCEL, NULL, NULL);
        SendMessage(hCancel, WM_SETFONT, (WPARAM)hf, TRUE);

        SetFocus(ctx->hCN);
        return 0;
    }
    case WM_COMMAND:
        if (ctx) {
            if (LOWORD(wParam) == IDC_SELF_GENERATE) {
                ctx->certType = (int)SendMessageW(ctx->hTypeCombo, CB_GETCURSEL, 0, 0);
                ctx->cn = GetEditText(ctx->hCN);
                if (ctx->cn.empty()) { MessageBoxW(hwnd, L"Common Name (CN) is required.", L"Self-Signed Certificate", MB_ICONINFORMATION); SetFocus(ctx->hCN); return 0; }
                ctx->org = GetEditText(ctx->hOrg);
                ctx->ou = GetEditText(ctx->hOU);
                ctx->loc = GetEditText(ctx->hLoc);
                ctx->state = GetEditText(ctx->hState);
                ctx->country = GetEditText(ctx->hCountry);
                ctx->email = GetEditText(ctx->hEmail);
                ctx->san = GetEditText(ctx->hSanEdit);
                if (ctx->certType == TLS_TYPE_TLS && ctx->san.empty()) {
                    MessageBoxW(hwnd, L"At least one Subject Alt Name (DNS) is required for TLS certificates.", L"Self-Signed TLS Certificate", MB_ICONINFORMATION); SetFocus(ctx->hSanEdit); return 0;
                }
                ctx->keyIdx = (int)SendMessageW(ctx->hKeyCombo, CB_GETCURSEL, 0, 0);
                wchar_t vbuf[16] = {};
                GetWindowTextW(ctx->hValidityEdit, vbuf, 16);
                ctx->validityYears = _wtoi(vbuf);
                ctx->confirmed = true;
                DestroyWindow(hwnd);
                return 0;
            }
            if (LOWORD(wParam) == IDC_SELF_CANCEL || LOWORD(wParam) == IDCANCEL) { DestroyWindow(hwnd); return 0; }
        }
        break;
    case WM_SIZE: {
        RECT rc; GetClientRect(hwnd, &rc);
        int cw = rc.right, ch = rc.bottom;
        HWND hChild = GetWindow(hwnd, GW_CHILD);
        int bottomY = ch - 40;
        while (hChild) {
            HWND hNext = GetWindow(hChild, GW_HWNDNEXT);
            wchar_t cls[32] = {};
            GetClassNameW(hChild, cls, 32);
            RECT cr = {}; GetWindowRect(hChild, &cr);
            ScreenToClient(hwnd, (POINT*)&cr);
            int origY = cr.top, origX = cr.left, origW = cr.right - cr.left, origH = cr.bottom - cr.top;
            if (wcscmp(cls, L"BUTTON") == 0) {
                if (origX > 210) {
                    int newBtnX = cw - origW - 12;
                    MoveWindow(hChild, newBtnX, origY, origW, origH, TRUE);
                } else {
                    MoveWindow(hChild, origX, bottomY, origW, origH, TRUE);
                }
            } else if (wcscmp(cls, L"EDIT") == 0 || wcscmp(cls, L"COMBOBOX") == 0) {
                int newW = cw - origX - 12;
                if (newW < 80) newW = 80;
                MoveWindow(hChild, origX, origY, newW, origH, TRUE);
            }
            hChild = hNext;
        }
        break;
    }
    case WM_CLOSE: DestroyWindow(hwnd); return 0;
    }
    return DefWindowProcW(hwnd, msg, wParam, lParam);
}

bool OpenSelfCertDialog(HWND parent, SelfCertDlgCtx* ctx) {
    if (!selfDlgClassRegistered) {
        WNDCLASSEXW wc = {};
        wc.cbSize = sizeof(wc);
        wc.lpfnWndProc = SelfCertDlgProc;
        wc.hInstance = g_hInstance;
        wc.hCursor = LoadCursor(NULL, IDC_ARROW);
        wc.hbrBackground = (HBRUSH)(COLOR_BTNFACE + 1);
        wc.lpszClassName = SELF_DLG_CLASS;
        RegisterClassExW(&wc);
        selfDlgClassRegistered = true;
    }
    int screenW = GetSystemMetrics(SM_CXSCREEN);
    int screenH = GetSystemMetrics(SM_CYSCREEN);
    int dlgW = 680, dlgH = 530;
    HWND hDlg = CreateWindowExW(WS_EX_DLGMODALFRAME | WS_EX_TOPMOST,
        SELF_DLG_CLASS, L"Create Self-Signed Certificate",
        WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU | WS_THICKFRAME | WS_MAXIMIZEBOX,
        (screenW - dlgW) / 2, (screenH - dlgH) / 2, dlgW, dlgH,
        parent, NULL, g_hInstance, ctx);
    if (!hDlg) return false;
    EnableWindow(parent, FALSE);
    ShowWindow(hDlg, SW_SHOW);
    MSG msg;
    while (IsWindow(hDlg)) {
        BOOL ret = GetMessageW(&msg, NULL, 0, 0);
        if (ret == 0 || ret == -1) break;
        if (!IsWindow(hDlg)) break;
        if (!IsDialogMessageW(hDlg, &msg)) { TranslateMessage(&msg); DispatchMessageW(&msg); }
    }
    EnableWindow(parent, TRUE);
    SetForegroundWindow(parent);
    return ctx->confirmed;
}

static bool BuildSelfSignedCert(
    int certType, const std::wstring& cn, const std::wstring& org, const std::wstring& ou,
    const std::wstring& loc, const std::wstring& state, const std::wstring& country,
    const std::wstring& email, const std::wstring& san, int keyIdx, int validityYears,
    std::string& outCertPem, std::string& outPrivPem, std::string& outInfo)
{
    // Generate key pair
    const wchar_t* ncryptAlgo = BCRYPT_RSA_ALGORITHM;
    const wchar_t* ecCurve = NULL;
    int rsaBits = 2048;
    bool isECC = false;
    switch (keyIdx) {
    case 0: rsaBits = 2048; break;
    case 1: rsaBits = 3072; break;
    case 2: rsaBits = 4096; break;
    case 3: ncryptAlgo = BCRYPT_ECDSA_ALGORITHM; ecCurve = BCRYPT_ECC_CURVE_NISTP256; isECC = true; break;
    case 4: ncryptAlgo = BCRYPT_ECDSA_ALGORITHM; ecCurve = BCRYPT_ECC_CURVE_NISTP384; isECC = true; break;
    case 5: ncryptAlgo = BCRYPT_ECDSA_ALGORITHM; ecCurve = BCRYPT_ECC_CURVE_NISTP521; isECC = true; break;
    }

    NCRYPT_PROV_HANDLE hProv = 0;
    NCRYPT_KEY_HANDLE hKey = 0;
    NTSTATUS st = NCryptOpenStorageProvider(&hProv, MS_KEY_STORAGE_PROVIDER, 0);
    if (!NT_SUCCESS(st)) { outInfo = "Failed to open NCrypt provider."; return false; }

    st = NCryptCreatePersistedKey(hProv, &hKey, ncryptAlgo, NULL, 0, 0);
    if (!NT_SUCCESS(st)) { NCryptFreeObject(hProv); outInfo = "Failed to create key."; return false; }

    if (isECC) {
        st = NCryptSetProperty(hKey, NCRYPT_ECC_CURVE_NAME_PROPERTY, (PBYTE)ecCurve,
            (DWORD)((wcslen(ecCurve) + 1) * sizeof(wchar_t)), 0);
    } else {
        st = NCryptSetProperty(hKey, NCRYPT_LENGTH_PROPERTY, (PBYTE)&rsaBits, sizeof(rsaBits), 0);
    }
    if (!NT_SUCCESS(st)) { NCryptFreeObject(hKey); NCryptFreeObject(hProv); outInfo = "Failed to set key property."; return false; }

    DWORD ep = NCRYPT_ALLOW_PLAINTEXT_EXPORT_FLAG | NCRYPT_ALLOW_EXPORT_FLAG;
    NCryptSetProperty(hKey, NCRYPT_EXPORT_POLICY_PROPERTY, (PBYTE)&ep, sizeof(ep), 0);
    st = NCryptFinalizeKey(hKey, 0);
    if (!NT_SUCCESS(st)) { NCryptFreeObject(hKey); NCryptFreeObject(hProv); outInfo = "Failed to finalize key."; return false; }

    // Export private key
    const wchar_t* privBlobType = isECC ? BCRYPT_ECCPRIVATE_BLOB : BCRYPT_RSAPRIVATE_BLOB;
    DWORD cb = 0;
    NCryptExportKey(hKey, 0, privBlobType, NULL, NULL, 0, &cb, 0);
    std::vector<unsigned char> privBlob(cb);
    NCryptExportKey(hKey, 0, privBlobType, NULL, privBlob.data(), cb, &cb, 0);
    outPrivPem = WrapPem(BytesToBase64(privBlob.data(), privBlob.size()),
        isECC ? "EC PRIVATE KEY" : "RSA PRIVATE KEY");

    // Export public key and build SPKI
    const wchar_t* pubBlobType = isECC ? BCRYPT_ECCPUBLIC_BLOB : BCRYPT_RSAPUBLIC_BLOB;
    cb = 0;
    NCryptExportKey(hKey, 0, pubBlobType, NULL, NULL, 0, &cb, 0);
    std::vector<unsigned char> pubBlob(cb);
    NCryptExportKey(hKey, 0, pubBlobType, NULL, pubBlob.data(), cb, &cb, 0);

    std::vector<unsigned char> spki;
    if (isECC) {
        const unsigned char oidEcPubKey[] = { 0x2A, 0x86, 0x48, 0xCE, 0x3D, 0x02, 0x01 };
        std::vector<unsigned char> curveOid;
        if (wcscmp(ecCurve, BCRYPT_ECC_CURVE_NISTP256) == 0) curveOid = { 0x2A, 0x86, 0x48, 0xCE, 0x3D, 0x03, 0x01, 0x07 };
        else if (wcscmp(ecCurve, BCRYPT_ECC_CURVE_NISTP384) == 0) curveOid = { 0x2B, 0x81, 0x04, 0x00, 0x22 };
        else curveOid = { 0x2B, 0x81, 0x04, 0x00, 0x23 };
        auto algId = DerSequence({ DerOid(oidEcPubKey, sizeof(oidEcPubKey)), DerOid(curveOid.data(), curveOid.size()) });
        DWORD keySize = 32;
        if (wcscmp(ecCurve, BCRYPT_ECC_CURVE_NISTP384) == 0) keySize = 48;
        else if (wcscmp(ecCurve, BCRYPT_ECC_CURVE_NISTP521) == 0) keySize = 66;
        std::vector<unsigned char> point;
        point.push_back(0x04);
        BYTE* x = pubBlob.data() + sizeof(BCRYPT_ECCKEY_BLOB);
        BYTE* y = x + keySize;
        point.insert(point.end(), x, x + keySize);
        point.insert(point.end(), y, y + keySize);
        spki = DerSequence({ algId, DerBitString(point) });
    } else {
        const unsigned char oidRsa[] = { 0x2A, 0x86, 0x48, 0x86, 0xF7, 0x0D, 0x01, 0x01, 0x01 };
        BCRYPT_RSAKEY_BLOB* rsaBlob = (BCRYPT_RSAKEY_BLOB*)pubBlob.data();
        BYTE* modulus = pubBlob.data() + sizeof(BCRYPT_RSAKEY_BLOB);
        BYTE* exp = modulus + rsaBlob->cbModulus;
        auto algId = DerSequence({ DerOid(oidRsa, sizeof(oidRsa)) });
        auto rsaPubKey = DerSequence({
            DerInteger(std::vector<unsigned char>(modulus, modulus + rsaBlob->cbModulus)),
            DerInteger(std::vector<unsigned char>(exp, exp + rsaBlob->cbPublicExp))
        });
        spki = DerSequence({ algId, DerBitString(rsaPubKey) });
    }

    // Build subject name
    std::vector<std::vector<unsigned char>> nameRdns;
    AddNameRdn(nameRdns, oidCN, sizeof(oidCN), cn);
    AddNameRdn(nameRdns, oidO, sizeof(oidO), org);
    AddNameRdn(nameRdns, oidOU, sizeof(oidOU), ou);
    AddNameRdn(nameRdns, oidL, sizeof(oidL), loc);
    AddNameRdn(nameRdns, oidS, sizeof(oidS), state);
    AddNameRdn(nameRdns, oidC, sizeof(oidC), country);
    AddNameRdn(nameRdns, oidE, sizeof(oidE), email);

    std::vector<unsigned char> nameContent;
    for (auto& rdn : nameRdns) nameContent.insert(nameContent.end(), rdn.begin(), rdn.end());
    auto subjectName = DerSequence({ nameContent });

    // Serial number
    std::vector<unsigned char> serial(16);
    BCryptGenRandom(NULL, serial.data(), 16, BCRYPT_USE_SYSTEM_PREFERRED_RNG);

    // Validity
    SYSTEMTIME nowUtc;
    GetSystemTime(&nowUtc);
    SYSTEMTIME notAfter = nowUtc;
    notAfter.wYear += (WORD)validityYears;
    if (validityYears > 9999 - nowUtc.wYear) notAfter.wYear = 9999;
    auto validity = DerSequence({ DerUtcTime(nowUtc), DerUtcTime(notAfter) });

    // Extensions based on cert type
    const unsigned char oidBC[] = { 0x55, 0x1D, 0x13 };
    const unsigned char oidKU[] = { 0x55, 0x1D, 0x0F };
    const unsigned char oidEKU[] = { 0x55, 0x1D, 0x25 };
    const unsigned char oidSAN[] = { 0x55, 0x1D, 0x11 };
    const unsigned char oidServerAuth[] = { 0x2B, 0x06, 0x01, 0x05, 0x05, 0x07, 0x03, 0x01 };
    const unsigned char oidClientAuth[] = { 0x2B, 0x06, 0x01, 0x05, 0x05, 0x07, 0x03, 0x02 };

    std::vector<std::vector<unsigned char>> exts;

    // Basic Constraints: CA:FALSE
    auto bcValue = DerSequence({ DerBoolean(false) });
    exts.push_back(DerSequence({ DerOid(oidBC, sizeof(oidBC)), DerBoolean(false), DerOctetString(bcValue) }));

    // Key Usage
    std::vector<unsigned char> kuBitStr;
    kuBitStr.push_back(0x03);
    if (certType == TLS_TYPE_USER) {
        kuBitStr.push_back(0x02);
        kuBitStr.push_back(0x06);
        kuBitStr.push_back(0x80);
    } else {
        kuBitStr.push_back(0x02);
        kuBitStr.push_back(0x05);
        kuBitStr.push_back(0xA0);
    }
    exts.push_back(DerSequence({ DerOid(oidKU, sizeof(oidKU)), DerBoolean(true), DerOctetString(kuBitStr) }));

    // Extended Key Usage
    if (certType == TLS_TYPE_USER) {
        auto ekuValue = DerSequence({ DerOid(oidClientAuth, sizeof(oidClientAuth)) });
        exts.push_back(DerSequence({ DerOid(oidEKU, sizeof(oidEKU)), DerOctetString(ekuValue) }));
    } else {
        auto ekuValue = DerSequence({ DerOid(oidServerAuth, sizeof(oidServerAuth)) });
        exts.push_back(DerSequence({ DerOid(oidEKU, sizeof(oidEKU)), DerOctetString(ekuValue) }));
    }

    // Subject Alternative Name
    if (certType != TLS_TYPE_USER) {
        auto sanEntries = SplitSanEntries(san);
        if (sanEntries.empty() && certType == TLS_TYPE_TLS) {
            NCryptFreeObject(hKey); NCryptFreeObject(hProv);
            outInfo = "TLS certificates require at least one Subject Alt Name (DNS name).";
            return false;
        }
        if (!sanEntries.empty()) {
            std::vector<std::vector<unsigned char>> sanItems;
            for (auto& entry : sanEntries) {
                auto dnsName = DerWrap(0xA2, DerIA5String(entry));
                sanItems.push_back(dnsName);
            }
            std::vector<unsigned char> sanContent;
            for (auto& item : sanItems) sanContent.insert(sanContent.end(), item.begin(), item.end());
            std::vector<std::vector<unsigned char>> sanSeqVec = { sanContent };
            auto sanValue = DerSequence(sanSeqVec);
            exts.push_back(DerSequence({ DerOid(oidSAN, sizeof(oidSAN)), DerOctetString(sanValue) }));
        }
    }

    auto extensions = DerSequence(exts);

    // Signature algorithm
    std::vector<unsigned char> sigAlgSeq;
    const unsigned char oidSha256[] = { 0x60, 0x86, 0x48, 0x01, 0x65, 0x03, 0x04, 0x02, 0x01 };
    if (isECC) {
        const unsigned char oidEcdsa[] = { 0x2A, 0x86, 0x48, 0xCE, 0x3D, 0x04, 0x01 };
        sigAlgSeq = DerSequence({ DerOid(oidEcdsa, sizeof(oidEcdsa)), DerOid(oidSha256, sizeof(oidSha256)) });
    } else {
        const unsigned char oidSha256Rsa[] = { 0x2A, 0x86, 0x48, 0x86, 0xF7, 0x0D, 0x01, 0x01, 0x0B };
        sigAlgSeq = DerSequence({ DerOid(oidSha256Rsa, sizeof(oidSha256Rsa)) });
    }

    // TBS Certificate (issuer = subject for self-signed)
    auto version = DerExplicitTag(0, DerIntegerFromSize(2));
    auto tbsCert = DerSequence({
        version, DerInteger(serial), sigAlgSeq,
        subjectName, validity, subjectName, spki,
        DerExplicitTag(3, extensions)
    });

    // Sign with own key
    auto hash = Sha256Hash(tbsCert.data(), tbsCert.size());
    BCRYPT_PKCS1_PADDING_INFO padInfo = {};
    padInfo.pszAlgId = BCRYPT_SHA256_ALGORITHM;
    DWORD signFlags = isECC ? 0 : BCRYPT_PAD_PKCS1;
    cb = 0;
    st = NCryptSignHash(hKey, &padInfo, hash.data(), (ULONG)hash.size(), NULL, 0, &cb, signFlags);
    if (!NT_SUCCESS(st)) {
        NCryptFreeObject(hKey); NCryptFreeObject(hProv);
        outInfo = "Failed to sign certificate. Error " + std::to_string(st);
        return false;
    }
    std::vector<unsigned char> sig(cb);
    st = NCryptSignHash(hKey, &padInfo, hash.data(), (ULONG)hash.size(), sig.data(), cb, &cb, signFlags);
    if (!NT_SUCCESS(st)) {
        NCryptFreeObject(hKey); NCryptFreeObject(hProv);
        outInfo = "Failed to sign certificate. Error " + std::to_string(st);
        return false;
    }

    auto cert = DerSequence({ tbsCert, sigAlgSeq, DerBitString(sig) });
    outCertPem = WrapPem(BytesToBase64(cert.data(), cert.size()), "CERTIFICATE");

    // Info
    const wchar_t* typeNames[] = { L"TLS Certificate", L"Server Certificate", L"User Certificate" };
    std::ostringstream oss;
    oss << "=== Self-Signed " << WstringToUtf8(typeNames[certType]) << " ===\r\n\r\n";
    oss << "--- Certificate (PEM) ---\r\n" << outCertPem << "\r\n\r\n";
    oss << "--- Private Key (PEM) ---\r\n" << outPrivPem << "\r\n\r\n";
    oss << "--- Details ---\r\n";
    oss << "Type: " << WstringToUtf8(typeNames[certType]) << "\r\n";
    oss << "Subject: " << WstringToUtf8(cn.empty() ? L"(none)" : cn);
    if (!org.empty()) oss << ", O=" << WstringToUtf8(org);
    if (!ou.empty()) oss << ", OU=" << WstringToUtf8(ou);
    if (!loc.empty()) oss << ", L=" << WstringToUtf8(loc);
    if (!state.empty()) oss << ", S=" << WstringToUtf8(state);
    if (!country.empty()) oss << ", C=" << WstringToUtf8(country);
    if (!email.empty()) oss << ", E=" << WstringToUtf8(email);
    oss << "\r\nIssuer: (self-signed)\r\n";
    oss << "Algorithm: " << (isECC ? "ECDSA" : "RSA") << "\r\n";
    if (isECC) oss << "Curve: " << WstringToUtf8(ecCurve) << "\r\n";
    else oss << "Key Size: " << rsaBits << " bits\r\n";
    oss << "Validity: " << validityYears << " year" << (validityYears != 1 ? "s" : "") << "\r\n";
    oss << "Key Usage: digitalSignature";
    if (certType != TLS_TYPE_USER) oss << ", keyEncipherment";
    oss << "\r\n";
    oss << "Extended Key Usage: " << (certType == TLS_TYPE_USER ? "Client Authentication" : "Server Authentication") << "\r\n";
    if (!san.empty() && certType != TLS_TYPE_USER) oss << "SAN: " << WstringToUtf8(san) << "\r\n";
    outInfo = oss.str();

    NCryptFreeObject(hKey);
    NCryptFreeObject(hProv);
    return true;
}

void HandleSelfCert(HWND hwnd, int certType = TLS_TYPE_TLS) {
    SelfCertDlgCtx ctx = {};
    ctx.certType = certType;
    if (!OpenSelfCertDialog(hwnd, &ctx)) return;

    int validityYears = ctx.validityYears;
    if (validityYears < 1) validityYears = 1;
    if (validityYears > 9999) validityYears = 9999;

    // Save type before dialog is destroyed
    int savedType = ctx.certType;

    std::string certPem, privPem, info;
    if (!BuildSelfSignedCert(savedType, ctx.cn, ctx.org, ctx.ou, ctx.loc, ctx.state, ctx.country, ctx.email,
        ctx.san, ctx.keyIdx, validityYears, certPem, privPem, info)) {
        SetStatus(L"Self-Signed Certificate: " + Utf8ToWstring(info));
        return;
    }

    SetEditText(hOutputEdit, Utf8ToWstring(info));
    SetStatus(L"Self-Signed Certificate created successfully.");
}

void HandleTlsCert(HWND hwnd, int certType = TLS_TYPE_TLS) {
    TlsDlgCtx ctx = {};
    ctx.initialCertType = certType;
    if (!OpenTlsDialog(hwnd, &ctx)) return;

    int validityYears = ctx.validityYears;
    if (validityYears < 1) validityYears = 1;
    if (validityYears > 9999) validityYears = 9999;

    std::string certPem, privPem, info;
    if (!BuildTlsCert(ctx.certType, ctx.cn, ctx.org, ctx.ou, ctx.loc, ctx.state, ctx.country, ctx.email,
        ctx.san, ctx.keyIdx, validityYears, ctx.caCertPath, ctx.caKeyPath,
        certPem, privPem, info)) {
        SetStatus(L"Certificate: " + Utf8ToWstring(info));
        return;
    }

    SetEditText(hOutputEdit, Utf8ToWstring(info));
    SetStatus(L"Certificate created successfully.");
}

// ===== PKCS#12 Manager =====

enum P12Mode { P12_CREATE = 0, P12_OPEN = 1, P12_ADD = 2 };

struct P12Item {
    std::string label;
    std::string type; // "cert" or "key"
    std::vector<unsigned char> derData;
};

struct P12DlgCtx {
    HWND hModeCombo, hFileEdit, hPasswordEdit;
    HWND hCertFileEdit, hKeyFileEdit;
    HWND hList;
    bool confirmed;
    int mode;
    std::wstring filePath, password, certFilePath, keyFilePath;
    std::vector<P12Item> items;
};

static const wchar_t P12_DLG_CLASS[] = L"P12DialogClass";
static bool p12DlgClassRegistered = false;

static void RefreshP12List(HWND hList, const std::vector<P12Item>& items) {
    SendMessageW(hList, LB_RESETCONTENT, 0, 0);
    for (size_t i = 0; i < items.size(); i++) {
        std::wstring label = Utf8ToWstring(items[i].label);
        SendMessageW(hList, LB_ADDSTRING, 0, (LPARAM)label.c_str());
    }
}

LRESULT CALLBACK P12DlgProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
    P12DlgCtx* ctx = NULL;
    if (msg == WM_NCCREATE) {
        ctx = (P12DlgCtx*)((CREATESTRUCTW*)lParam)->lpCreateParams;
        SetWindowLongPtr(hwnd, GWLP_USERDATA, (LONG_PTR)ctx);
        return DefWindowProcW(hwnd, msg, wParam, lParam);
    }
    ctx = (P12DlgCtx*)GetWindowLongPtr(hwnd, GWLP_USERDATA);
    if (!ctx) return DefWindowProcW(hwnd, msg, wParam, lParam);

    switch (msg) {
    case WM_CREATE: {
        HFONT hf = hBoldFont ? hBoldFont : (HFONT)GetStockObject(DEFAULT_GUI_FONT);
        HFONT hnf = hFont ? hFont : (HFONT)GetStockObject(SYSTEM_FONT);
        int y = 10;
        auto addLabel = [&](const wchar_t* text, int lblW) {
            HWND h = CreateWindowW(L"STATIC", text, WS_CHILD | WS_VISIBLE, 10, y + 3, lblW, 20, hwnd, NULL, NULL, NULL);
            SendMessage(h, WM_SETFONT, (WPARAM)hf, TRUE);
        };
        auto addEdit = [&](int id, int exW) {
            HWND h = CreateWindowExW(WS_EX_CLIENTEDGE, L"EDIT", L"",
                WS_CHILD | WS_VISIBLE | WS_TABSTOP, 10 + 140, y, exW, 23, hwnd, (HMENU)(INT_PTR)id, NULL, NULL);
            SendMessage(h, WM_SETFONT, (WPARAM)hnf, TRUE);
            return h;
        };

        addLabel(L"Operation:", 135);
        ctx->hModeCombo = CreateWindowExW(0, L"COMBOBOX", L"",
            WS_CHILD | WS_VISIBLE | WS_TABSTOP | CBS_DROPDOWNLIST,
            10 + 140, y, 250, 200, hwnd, (HMENU)(INT_PTR)IDC_P12_MODE, NULL, NULL);
        SendMessage(ctx->hModeCombo, WM_SETFONT, (WPARAM)hf, TRUE);
        SendMessageW(ctx->hModeCombo, CB_ADDSTRING, 0, (LPARAM)L"Create New PKCS#12");
        SendMessageW(ctx->hModeCombo, CB_ADDSTRING, 0, (LPARAM)L"Open Existing PKCS#12");
        SendMessageW(ctx->hModeCombo, CB_ADDSTRING, 0, (LPARAM)L"Add to Existing PKCS#12");
        SendMessage(ctx->hModeCombo, CB_SETCURSEL, 0, 0);
        y += 33;

        addLabel(L"PKCS#12 File:", 135);
        ctx->hFileEdit = addEdit(IDC_P12_FILE, 300);
        HWND hBrowse = CreateWindowW(L"BUTTON", L"Browse...",
            WS_CHILD | WS_VISIBLE | WS_TABSTOP, 10 + 445, y, 75, 23, hwnd, (HMENU)(INT_PTR)IDC_P12_FILE_BROWSE, NULL, NULL);
        SendMessage(hBrowse, WM_SETFONT, (WPARAM)hf, TRUE);
        y += 30;

        addLabel(L"Password:", 135);
        ctx->hPasswordEdit = CreateWindowExW(WS_EX_CLIENTEDGE, L"EDIT", L"",
            WS_CHILD | WS_VISIBLE | WS_TABSTOP | ES_PASSWORD, 10 + 140, y, 200, 23, hwnd, (HMENU)(INT_PTR)IDC_P12_PASSWORD, NULL, NULL);
        SendMessage(ctx->hPasswordEdit, WM_SETFONT, (WPARAM)hnf, TRUE);
        y += 30;

        addLabel(L"Certificate (PEM):", 135);
        ctx->hCertFileEdit = addEdit(IDC_P12_CERT_FILE, 300);
        HWND hBrowseCert = CreateWindowW(L"BUTTON", L"Browse...",
            WS_CHILD | WS_VISIBLE | WS_TABSTOP, 10 + 445, y, 75, 23, hwnd, (HMENU)(INT_PTR)IDC_P12_CERT_BROWSE, NULL, NULL);
        SendMessage(hBrowseCert, WM_SETFONT, (WPARAM)hf, TRUE);
        y += 30;

        addLabel(L"Private Key (PEM):", 135);
        ctx->hKeyFileEdit = addEdit(IDC_P12_KEY_FILE, 300);
        HWND hBrowseKey = CreateWindowW(L"BUTTON", L"Browse...",
            WS_CHILD | WS_VISIBLE | WS_TABSTOP, 10 + 445, y, 75, 23, hwnd, (HMENU)(INT_PTR)IDC_P12_KEY_BROWSE, NULL, NULL);
        SendMessage(hBrowseKey, WM_SETFONT, (WPARAM)hf, TRUE);
        y += 30;

        HWND hAddCert = CreateWindowW(L"BUTTON", L"Add Certificate",
            WS_CHILD | WS_VISIBLE | WS_TABSTOP, 10 + 140, y, 120, 25, hwnd, (HMENU)(INT_PTR)IDC_P12_ADD_CERT, NULL, NULL);
        SendMessage(hAddCert, WM_SETFONT, (WPARAM)hf, TRUE);

        HWND hAddKey = CreateWindowW(L"BUTTON", L"Add Private Key",
            WS_CHILD | WS_VISIBLE | WS_TABSTOP, 10 + 270, y, 120, 25, hwnd, (HMENU)(INT_PTR)IDC_P12_ADD_KEY, NULL, NULL);
        SendMessage(hAddKey, WM_SETFONT, (WPARAM)hf, TRUE);

        HWND hRemove = CreateWindowW(L"BUTTON", L"Remove",
            WS_CHILD | WS_VISIBLE | WS_TABSTOP, 10 + 400, y, 120, 25, hwnd, (HMENU)(INT_PTR)IDC_P12_REMOVE, NULL, NULL);
        SendMessage(hRemove, WM_SETFONT, (WPARAM)hf, TRUE);
        y += 33;

        ctx->hList = CreateWindowExW(WS_EX_CLIENTEDGE, L"LISTBOX", L"",
            WS_CHILD | WS_VISIBLE | WS_TABSTOP | WS_VSCROLL | LBS_NOTIFY,
            10, y, 510, 140, hwnd, (HMENU)(INT_PTR)IDC_P12_LIST, NULL, NULL);
        SendMessage(ctx->hList, WM_SETFONT, (WPARAM)hnf, TRUE);
        y += 148;

        HWND hSave = CreateWindowW(L"BUTTON", L"Save PKCS#12",
            WS_CHILD | WS_VISIBLE | WS_TABSTOP | BS_DEFPUSHBUTTON,
            10, y, 120, 30, hwnd, (HMENU)(INT_PTR)IDC_P12_SAVE, NULL, NULL);
        SendMessage(hSave, WM_SETFONT, (WPARAM)hf, TRUE);

        HWND hCancel = CreateWindowW(L"BUTTON", L"Cancel",
            WS_CHILD | WS_VISIBLE | WS_TABSTOP,
            140, y, 90, 30, hwnd, (HMENU)(INT_PTR)IDC_P12_CANCEL, NULL, NULL);
        SendMessage(hCancel, WM_SETFONT, (WPARAM)hf, TRUE);

        return 0;
    }
    case WM_COMMAND:
        if (ctx) {
            if (LOWORD(wParam) == IDC_P12_FILE_BROWSE) {
                wchar_t fn[MAX_PATH] = L"";
                OPENFILENAMEW ofn = {}; ofn.lStructSize = sizeof(ofn);
                ofn.hwndOwner = hwnd;
                int curMode = (int)SendMessageW(ctx->hModeCombo, CB_GETCURSEL, 0, 0);
                if (curMode == P12_CREATE) {
                    ofn.lpstrFilter = L"PKCS#12 Files (*.pfx;*.p12)\0*.pfx;*.p12\0All Files (*.*)\0*.*\0";
                    ofn.lpstrTitle = L"Save PKCS#12 File";
                    ofn.lpstrDefExt = L"pfx";
                    ofn.lpstrFile = fn; ofn.nMaxFile = MAX_PATH;
                    ofn.Flags = OFN_OVERWRITEPROMPT;
                    if (GetSaveFileNameW(&ofn)) SetWindowTextW(ctx->hFileEdit, fn);
                } else {
                    ofn.lpstrFilter = L"PKCS#12 Files (*.pfx;*.p12)\0*.pfx;*.p12\0All Files (*.*)\0*.*\0";
                    ofn.lpstrTitle = L"Open PKCS#12 File";
                    ofn.lpstrFile = fn; ofn.nMaxFile = MAX_PATH;
                    ofn.Flags = OFN_FILEMUSTEXIST | OFN_PATHMUSTEXIST;
                    if (GetOpenFileNameW(&ofn)) SetWindowTextW(ctx->hFileEdit, fn);
                }
                return 0;
            }
            if (LOWORD(wParam) == IDC_P12_CERT_BROWSE) {
                wchar_t fn[MAX_PATH] = L"";
                OPENFILENAMEW ofn = {}; ofn.lStructSize = sizeof(ofn);
                ofn.hwndOwner = hwnd;
                ofn.lpstrFilter = L"PEM Files (*.pem)\0*.pem\0All Files (*.*)\0*.*\0";
                ofn.lpstrTitle = L"Select Certificate"; ofn.Flags = OFN_FILEMUSTEXIST | OFN_PATHMUSTEXIST;
                ofn.lpstrFile = fn; ofn.nMaxFile = MAX_PATH;
                if (GetOpenFileNameW(&ofn)) SetWindowTextW(ctx->hCertFileEdit, fn);
                return 0;
            }
            if (LOWORD(wParam) == IDC_P12_KEY_BROWSE) {
                wchar_t fn[MAX_PATH] = L"";
                OPENFILENAMEW ofn = {}; ofn.lStructSize = sizeof(ofn);
                ofn.hwndOwner = hwnd;
                ofn.lpstrFilter = L"PEM Files (*.pem)\0*.pem\0All Files (*.*)\0*.*\0";
                ofn.lpstrTitle = L"Select Private Key"; ofn.Flags = OFN_FILEMUSTEXIST | OFN_PATHMUSTEXIST;
                ofn.lpstrFile = fn; ofn.nMaxFile = MAX_PATH;
                if (GetOpenFileNameW(&ofn)) SetWindowTextW(ctx->hKeyFileEdit, fn);
                return 0;
            }
            if (LOWORD(wParam) == IDC_P12_ADD_CERT) {
                wchar_t certPath[MAX_PATH] = {};
                GetWindowTextW(ctx->hCertFileEdit, certPath, MAX_PATH);
                if (wcslen(certPath) == 0) { MessageBoxW(hwnd, L"Select a certificate file first.", L"PKCS#12", MB_ICONINFORMATION); return 0; }
                std::string certPem = ReadFileToString(certPath);
                if (certPem.empty()) { MessageBoxW(hwnd, L"Failed to read certificate file.", L"PKCS#12", MB_ICONERROR); return 0; }
                auto certDer = PemToDer(certPem, "CERTIFICATE");
                if (certDer.empty()) { MessageBoxW(hwnd, L"Failed to parse certificate PEM.", L"PKCS#12", MB_ICONERROR); return 0; }

                PCCERT_CONTEXT pCert = CertCreateCertificateContext(
                    X509_ASN_ENCODING | PKCS_7_ASN_ENCODING, certDer.data(), (DWORD)certDer.size());
                if (!pCert) { MessageBoxW(hwnd, L"Failed to decode certificate.", L"PKCS#12", MB_ICONERROR); return 0; }

                DWORD cnSize = CertNameToStrA(X509_ASN_ENCODING | PKCS_7_ASN_ENCODING,
                    &pCert->pCertInfo->Subject, CERT_SIMPLE_NAME_STR, NULL, 0);
                std::vector<char> cnBuf(cnSize);
                CertNameToStrA(X509_ASN_ENCODING | PKCS_7_ASN_ENCODING,
                    &pCert->pCertInfo->Subject, CERT_SIMPLE_NAME_STR, cnBuf.data(), cnSize);

                P12Item item;
                item.type = "cert";
                item.label = "Certificate: " + std::string(cnBuf.data());
                item.derData = certDer;
                ctx->items.push_back(item);
                RefreshP12List(ctx->hList, ctx->items);
                CertFreeCertificateContext(pCert);
                SetWindowTextW(ctx->hCertFileEdit, L"");
                return 0;
            }
            if (LOWORD(wParam) == IDC_P12_ADD_KEY) {
                wchar_t keyPath[MAX_PATH] = {};
                GetWindowTextW(ctx->hKeyFileEdit, keyPath, MAX_PATH);
                if (wcslen(keyPath) == 0) { MessageBoxW(hwnd, L"Select a private key file first.", L"PKCS#12", MB_ICONINFORMATION); return 0; }
                std::string keyPem = ReadFileToString(keyPath);
                if (keyPem.empty()) { MessageBoxW(hwnd, L"Failed to read key file.", L"PKCS#12", MB_ICONERROR); return 0; }
                auto keyDer = PemToDer(keyPem, "RSA PRIVATE KEY");
                if (keyDer.empty()) keyDer = PemToDer(keyPem, "EC PRIVATE KEY");
                if (keyDer.empty()) keyDer = PemToDer(keyPem, "PRIVATE KEY");
                if (keyDer.empty()) { MessageBoxW(hwnd, L"Failed to parse private key PEM.", L"PKCS#12", MB_ICONERROR); return 0; }

                std::string keyType = "RSA Private Key";
                if (PemToDer(keyPem, "EC PRIVATE KEY").size() > 0) keyType = "EC Private Key";

                P12Item item;
                item.type = "key";
                item.label = keyType;
                item.derData = keyDer;
                ctx->items.push_back(item);
                RefreshP12List(ctx->hList, ctx->items);
                SetWindowTextW(ctx->hKeyFileEdit, L"");
                return 0;
            }
            if (LOWORD(wParam) == IDC_P12_REMOVE) {
                int sel = (int)SendMessageW(ctx->hList, LB_GETCURSEL, 0, 0);
                if (sel >= 0 && sel < (int)ctx->items.size()) {
                    ctx->items.erase(ctx->items.begin() + sel);
                    RefreshP12List(ctx->hList, ctx->items);
                }
                return 0;
            }
            if (LOWORD(wParam) == IDC_P12_SAVE) {
                ctx->filePath.resize(MAX_PATH);
                GetWindowTextW(ctx->hFileEdit, &ctx->filePath[0], MAX_PATH);
                ctx->filePath.resize(wcslen(ctx->filePath.c_str()));
                ctx->password.resize(MAX_PATH);
                GetWindowTextW(ctx->hPasswordEdit, &ctx->password[0], MAX_PATH);
                ctx->password.resize(wcslen(ctx->password.c_str()));
                if (ctx->filePath.empty()) { MessageBoxW(hwnd, L"Enter a PKCS#12 file path.", L"PKCS#12", MB_ICONINFORMATION); return 0; }
                if (ctx->items.empty()) { MessageBoxW(hwnd, L"Add at least one certificate or key.", L"PKCS#12", MB_ICONINFORMATION); return 0; }
                ctx->confirmed = true;
                DestroyWindow(hwnd);
                return 0;
            }
            if (LOWORD(wParam) == IDC_P12_CANCEL || LOWORD(wParam) == IDCANCEL) { DestroyWindow(hwnd); return 0; }
        }
        break;
    case WM_SIZE: {
        RECT rc; GetClientRect(hwnd, &rc);
        int cw = rc.right, ch = rc.bottom;
        HWND hChild = GetWindow(hwnd, GW_CHILD);
        int bottomY = ch - 40;
        while (hChild) {
            HWND hNext = GetWindow(hChild, GW_HWNDNEXT);
            wchar_t cls[32] = {};
            GetClassNameW(hChild, cls, 32);
            RECT cr = {}; GetWindowRect(hChild, &cr);
            ScreenToClient(hwnd, (POINT*)&cr);
            int origY = cr.top, origX = cr.left, origW = cr.right - cr.left, origH = cr.bottom - cr.top;
            int ctrlId = GetDlgCtrlID(hChild);
            if (ctrlId == IDC_P12_LIST) {
                MoveWindow(hChild, origX, origY, cw - origX - 12, bottomY - origY - 5, TRUE);
            } else if (ctrlId == IDC_P12_SAVE || ctrlId == IDC_P12_CANCEL) {
                MoveWindow(hChild, origX, bottomY, origW, origH, TRUE);
            } else if (wcscmp(cls, L"BUTTON") == 0 && origX > 400) {
                int newBtnX = cw - origW - 12;
                MoveWindow(hChild, newBtnX, origY, origW, origH, TRUE);
            } else if (wcscmp(cls, L"EDIT") == 0 || wcscmp(cls, L"COMBOBOX") == 0) {
                int newW = cw - origX - 12;
                if (ctrlId == IDC_P12_PASSWORD || ctrlId == IDC_P12_MODE) newW = 200;
                if (newW < 80) newW = 80;
                MoveWindow(hChild, origX, origY, newW, origH, TRUE);
            }
            hChild = hNext;
        }
        break;
    }
    case WM_CLOSE: DestroyWindow(hwnd); return 0;
    }
    return DefWindowProcW(hwnd, msg, wParam, lParam);
}

bool OpenP12Dialog(HWND parent, P12DlgCtx* ctx) {
    if (!p12DlgClassRegistered) {
        WNDCLASSEXW wc = {};
        wc.cbSize = sizeof(wc);
        wc.lpfnWndProc = P12DlgProc;
        wc.hInstance = g_hInstance;
        wc.hCursor = LoadCursor(NULL, IDC_ARROW);
        wc.hbrBackground = (HBRUSH)(COLOR_BTNFACE + 1);
        wc.lpszClassName = P12_DLG_CLASS;
        RegisterClassExW(&wc);
        p12DlgClassRegistered = true;
    }
    int screenW = GetSystemMetrics(SM_CXSCREEN);
    int screenH = GetSystemMetrics(SM_CYSCREEN);
    int dlgW = 680, dlgH = 580;
    HWND hDlg = CreateWindowExW(WS_EX_DLGMODALFRAME | WS_EX_TOPMOST,
        P12_DLG_CLASS, L"PKCS#12 Manager",
        WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU | WS_THICKFRAME | WS_MAXIMIZEBOX,
        (screenW - dlgW) / 2, (screenH - dlgH) / 2, dlgW, dlgH,
        parent, NULL, g_hInstance, ctx);
    if (!hDlg) return false;
    EnableWindow(parent, FALSE);
    ShowWindow(hDlg, SW_SHOW);
    MSG msg;
    while (IsWindow(hDlg)) {
        BOOL ret = GetMessageW(&msg, NULL, 0, 0);
        if (ret == 0 || ret == -1) break;
        if (!IsWindow(hDlg)) break;
        if (!IsDialogMessageW(hDlg, &msg)) { TranslateMessage(&msg); DispatchMessageW(&msg); }
    }
    EnableWindow(parent, TRUE);
    SetForegroundWindow(parent);
    return ctx->confirmed;
}

void HandleP12(HWND hwnd) {
    P12DlgCtx ctx = {};
    if (!OpenP12Dialog(hwnd, &ctx)) return;

    // Build in-memory cert store, add all items, export as PKCS#12
    HCERTSTORE hStore = CertOpenStore(
        CERT_STORE_PROV_MEMORY, 0, 0,
        CERT_STORE_CREATE_NEW_FLAG, NULL);
    if (!hStore) { SetStatus(L"PKCS#12: Failed to create memory store."); return; }

    bool hasKey = false;
    for (auto& item : ctx.items) {
        if (item.type == "cert") {
            PCCERT_CONTEXT pCert = NULL;
            BOOL ok = CertAddEncodedCertificateToStore(hStore,
                X509_ASN_ENCODING | PKCS_7_ASN_ENCODING,
                item.derData.data(), (DWORD)item.derData.size(),
                CERT_STORE_ADD_NEW, &pCert);
            if (ok && pCert) {
                CertFreeCertificateContext(pCert);
            }
        } else if (item.type == "key") {
            hasKey = true;
        }
    }

    // For private keys, associate with matching certificate via CAPI
    for (auto& item : ctx.items) {
        if (item.type != "key") continue;

        bool isECC = (item.label.find("EC") != std::string::npos);
        if (isECC) continue;

        HCRYPTPROV hCAPIProv = 0;
        if (!CryptAcquireContextW(&hCAPIProv, L"P12TempKey", MS_ENH_RSA_AES_PROV, PROV_RSA_AES, CRYPT_NEWKEYSET)) {
            if (!CryptAcquireContextW(&hCAPIProv, L"P12TempKey", MS_ENH_RSA_AES_PROV, PROV_RSA_AES, 0)) continue;
        }

        HCRYPTKEY hCAPIKey = 0;
        if (CryptImportKey(hCAPIProv, item.derData.data(), (DWORD)item.derData.size(), 0, 0, &hCAPIKey)) {
            PCCERT_CONTEXT pCert = NULL;
            while ((pCert = CertEnumCertificatesInStore(hStore, pCert)) != NULL) {
                DWORD provInfoSize = 0;
                if (CertGetCertificateContextProperty(pCert, CERT_KEY_PROV_INFO_PROP_ID, NULL, &provInfoSize)) continue;
                CRYPT_KEY_PROV_INFO keyProvInfo = {};
                keyProvInfo.pwszContainerName = L"P12TempKey";
                keyProvInfo.pwszProvName = MS_ENH_RSA_AES_PROV;
                keyProvInfo.dwProvType = PROV_RSA_AES;
                keyProvInfo.dwKeySpec = AT_KEYEXCHANGE;
                CertSetCertificateContextProperty(pCert, CERT_KEY_PROV_INFO_PROP_ID, 0, &keyProvInfo);
                break;
            }
            CryptDestroyKey(hCAPIKey);
        }

        CryptReleaseContext(hCAPIProv, 0);
    }

    // Export as PKCS#12
    CRYPT_DATA_BLOB pfxBlob = {};
    DWORD exportFlags = EXPORT_PRIVATE_KEYS | PKCS12_EXPORT_SILENT;
    BOOL expOk = PFXExportCertStoreEx(hStore, &pfxBlob, ctx.password.c_str(), NULL, exportFlags);
    if (!expOk) {
        CertCloseStore(hStore, CERT_CLOSE_STORE_CHECK_FLAG);
        SetStatus(L"PKCS#12: Failed to calculate export size.");
        return;
    }

    pfxBlob.pbData = (BYTE*)malloc(pfxBlob.cbData);
    if (!pfxBlob.pbData) { CertCloseStore(hStore, CERT_CLOSE_STORE_CHECK_FLAG); SetStatus(L"PKCS#12: Out of memory."); return; }

    expOk = PFXExportCertStoreEx(hStore, &pfxBlob, ctx.password.c_str(), NULL, exportFlags);
    if (!expOk) {
        free(pfxBlob.pbData);
        CertCloseStore(hStore, CERT_CLOSE_STORE_CHECK_FLAG);
        SetStatus(L"PKCS#12: Failed to export PKCS#12.");
        return;
    }

    // Save to file
    std::wstring filePathW = ctx.filePath;
    HANDLE hFile = CreateFileW(filePathW.c_str(), GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
    if (hFile == INVALID_HANDLE_VALUE) {
        free(pfxBlob.pbData);
        CertCloseStore(hStore, CERT_CLOSE_STORE_CHECK_FLAG);
        SetStatus(L"PKCS#12: Failed to create output file.");
        return;
    }
    DWORD written = 0;
    WriteFile(hFile, pfxBlob.pbData, pfxBlob.cbData, &written, NULL);
    CloseHandle(hFile);

    // Also put hex + base64 in output
    std::string hexStr, b64Str;
    hexStr = BytesToHex(pfxBlob.pbData, pfxBlob.cbData);
    b64Str = BytesToBase64(pfxBlob.pbData, pfxBlob.cbData);

    free(pfxBlob.pbData);
    CertCloseStore(hStore, CERT_CLOSE_STORE_CHECK_FLAG);

    std::ostringstream oss;
    oss << "=== PKCS#12 File Created ===\r\n\r\n";
    oss << "File: " << WstringToUtf8(filePathW) << "\r\n";
    oss << "Size: " << written << " bytes\r\n";
    oss << "Contents: " << ctx.items.size() << " item(s)\r\n";
    for (auto& item : ctx.items) {
        oss << "  - " << item.label << "\r\n";
    }
    oss << "\r\n--- Base64 ---\r\n" << b64Str << "\r\n";
    oss << "\r\n--- Hex ---\r\n" << hexStr << "\r\n";

    SetEditText(hOutputEdit, Utf8ToWstring(oss.str()));
    SetStatus(L"PKCS#12 file saved successfully.");
}

// ===== Main window helpers =====
void PerformSwap() {
    std::wstring output = GetEditText(hOutputEdit);
    SetEditText(hInputEdit, output);
    SetStatus(L"Swapped output to input.");
}

void ClearBoth() {
    SetEditText(hInputEdit, L""); SetEditText(hOutputEdit, L""); SetStatus(L"Cleared.");
}

void CopyOutputToClipboard() {
    std::wstring text = GetEditText(hOutputEdit);
    if (text.empty()) return;
    if (OpenClipboard(NULL)) {
        EmptyClipboard();
        size_t sz = (text.size() + 1) * sizeof(wchar_t);
        HGLOBAL hMem = GlobalAlloc(GMEM_MOVEABLE, sz);
        if (hMem) { memcpy(GlobalLock(hMem), text.c_str(), sz); GlobalUnlock(hMem); SetClipboardData(CF_UNICODETEXT, hMem); }
        CloseClipboard(); SetStatus(L"Output copied to clipboard.");
    }
}

void PasteFromClipboardToInput() {
    if (IsClipboardFormatAvailable(CF_UNICODETEXT) && OpenClipboard(NULL)) {
        HANDLE hData = GetClipboardData(CF_UNICODETEXT);
        if (hData) { wchar_t* p = (wchar_t*)GlobalLock(hData); if (p) { SetEditText(hInputEdit, p); GlobalUnlock(hData); SetStatus(L"Pasted from clipboard."); } }
        CloseClipboard();
    }
}

void OpenFileDialog() {
    wchar_t fn[MAX_PATH] = L"";
    OPENFILENAMEW ofn = {}; ofn.lStructSize = sizeof(ofn);
    ofn.lpstrFilter = L"Text Files (*.txt)\0*.txt\0All Files (*.*)\0*.*\0";
    ofn.lpstrFile = fn; ofn.nMaxFile = MAX_PATH;
    ofn.Flags = OFN_FILEMUSTEXIST | OFN_PATHMUSTEXIST; ofn.lpstrTitle = L"Open File";
    if (GetOpenFileNameW(&ofn)) {
        HANDLE hFile = CreateFileW(fn, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
        if (hFile != INVALID_HANDLE_VALUE) {
            DWORD sz = GetFileSize(hFile, NULL);
            if (sz != INVALID_FILE_SIZE && sz > 0) {
                std::vector<char> buf(sz + 1, 0); DWORD br;
                ReadFile(hFile, &buf[0], sz, &br, NULL);
                SetEditText(hInputEdit, Utf8ToWstring(std::string(buf.begin(), buf.begin() + br)));
                SetStatus(L"Loaded: " + std::wstring(fn));
            }
            CloseHandle(hFile);
        }
    }
}

void SaveFileDialog() {
    std::wstring output = GetEditText(hOutputEdit);
    if (output.empty()) { SetStatus(L"Output is empty."); return; }
    wchar_t fn[MAX_PATH] = L"output.txt";
    OPENFILENAMEW ofn = {}; ofn.lStructSize = sizeof(ofn);
    ofn.lpstrFilter = L"Text Files (*.txt)\0*.txt\0All Files (*.*)\0*.*\0";
    ofn.lpstrFile = fn; ofn.nMaxFile = MAX_PATH;
    ofn.Flags = OFN_OVERWRITEPROMPT; ofn.lpstrTitle = L"Save File";
    if (GetSaveFileNameW(&ofn)) {
        std::string content = WstringToUtf8(output);
        HANDLE hFile = CreateFileW(fn, GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
        if (hFile != INVALID_HANDLE_VALUE) { DWORD w; WriteFile(hFile, content.c_str(), (DWORD)content.size(), &w, NULL); CloseHandle(hFile); SetStatus(L"Saved: " + std::wstring(fn)); }
    }
}

void ShowAbout() {
    MessageBoxW(NULL,
        L"Encoding Converter & Key Generator v2.0\n\n"
        L"Encoding: Base64, Hex, URL, Binary, Unicode\n"
        L"Key Gen: RSA, ECDSA, ECDH, DSA, DH,\n"
        L"         AES, 3DES, ChaCha20, Random Bytes\n\n"
        L"Built with Win32 API + Windows CNG",
        L"About", MB_OK | MB_ICONINFORMATION);
}

// ===== WINDOW PROCEDURE =====
LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
    switch (msg) {
    case WM_CREATE: {
        hFont = CreateFontW(-14, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE,
            DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS,
            DEFAULT_QUALITY, DEFAULT_PITCH | FF_DONTCARE, L"Consolas");
        hBoldFont = CreateFontW(-16, 0, 0, 0, FW_BOLD, FALSE, FALSE, FALSE,
            DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS,
            DEFAULT_QUALITY, DEFAULT_PITCH | FF_DONTCARE, L"Segoe UI");

        hModeLabel = CreateWindowW(L"STATIC", L"Key Generator — Output Panel",
            WS_CHILD | WS_VISIBLE, 10, 10, 300, 25, hwnd, NULL, NULL, NULL);
        SendMessage(hModeLabel, WM_SETFONT, (WPARAM)hBoldFont, TRUE);

        HWND hInputLabel = CreateWindowW(L"STATIC", L"Input:",
            WS_CHILD | WS_VISIBLE, 10, 45, 60, 22, hwnd, NULL, NULL, NULL);
        SendMessage(hInputLabel, WM_SETFONT, (WPARAM)hBoldFont, TRUE);

        hInputEdit = CreateWindowExW(WS_EX_CLIENTEDGE, L"EDIT", L"",
            WS_CHILD | WS_VISIBLE | WS_VSCROLL | WS_HSCROLL | ES_MULTILINE | ES_AUTOVSCROLL,
            10, 70, 560, 180, hwnd, (HMENU)ID_INPUT_EDIT, NULL, NULL);
        SendMessage(hInputEdit, WM_SETFONT, (WPARAM)hFont, TRUE);

        hSwapBtn = CreateWindowW(L"BUTTON", L"Swap",
            WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
            580, 70, 100, 35, hwnd, (HMENU)ID_SWAP_BTN, NULL, NULL);
        SendMessage(hSwapBtn, WM_SETFONT, (WPARAM)hBoldFont, TRUE);

        hClearBtn = CreateWindowW(L"BUTTON", L"Clear",
            WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
            580, 112, 100, 35, hwnd, (HMENU)ID_CLEAR_BTN, NULL, NULL);
        SendMessage(hClearBtn, WM_SETFONT, (WPARAM)hBoldFont, TRUE);

        HWND hOutputLabel = CreateWindowW(L"STATIC", L"Output:",
            WS_CHILD | WS_VISIBLE, 10, 260, 60, 22, hwnd, NULL, NULL, NULL);
        SendMessage(hOutputLabel, WM_SETFONT, (WPARAM)hBoldFont, TRUE);

        hOutputEdit = CreateWindowExW(WS_EX_CLIENTEDGE, L"EDIT", L"",
            WS_CHILD | WS_VISIBLE | WS_VSCROLL | WS_HSCROLL | ES_MULTILINE | ES_AUTOVSCROLL | ES_READONLY,
            10, 285, 670, 150, hwnd, (HMENU)ID_OUTPUT_EDIT, NULL, NULL);
        SendMessage(hOutputEdit, WM_SETFONT, (WPARAM)hFont, TRUE);

        hStatusLabel = CreateWindowW(L"STATIC", L"Ready.",
            WS_CHILD | WS_VISIBLE | SS_LEFT,
            10, 445, 670, 22, hwnd, NULL, NULL, NULL);
        SendMessage(hStatusLabel, WM_SETFONT, (WPARAM)hFont, TRUE);
        break;
    }
    case WM_SIZE: {
        int w = LOWORD(lParam), h = HIWORD(lParam);
        int inputH = (h - 160) / 2, outputH = h - 160 - inputH - 50;
        int sideW = 110, mainW = w - sideW - 30;
        MoveWindow(hModeLabel, 10, 10, 300, 25, TRUE);
        MoveWindow(hInputEdit, 10, 70, mainW, inputH, TRUE);
        MoveWindow(hSwapBtn, mainW + 20, 70, sideW, 35, TRUE);
        MoveWindow(hClearBtn, mainW + 20, 112, sideW, 35, TRUE);
        int outputY = 70 + inputH + 40;
        MoveWindow(hOutputEdit, 10, outputY, mainW, outputH, TRUE);
        MoveWindow(hStatusLabel, 10, outputY + outputH + 10, mainW, 22, TRUE);
        break;
    }
    case WM_COMMAND: {
        switch (LOWORD(wParam)) {
        case ID_CLEAR_BTN:   ClearBoth(); break;
        case ID_SWAP_BTN:    PerformSwap(); break;
        case ID_MENU_COPY_OUTPUT: CopyOutputToClipboard(); break;
        case ID_MENU_PASTE_INPUT: PasteFromClipboardToInput(); break;
        case ID_MENU_CLEAR_BOTH:  ClearBoth(); break;
        case ID_MENU_FILE_OPEN:   OpenFileDialog(); break;
        case ID_MENU_FILE_SAVE:   SaveFileDialog(); break;

        case ID_MENU_ENCODING_DIALOG: OpenEncodingDialog(hwnd); break;
        case ID_MENU_CSR:             HandleCSR(hwnd); break;
        case ID_MENU_PKCS7:           HandlePKCS7(hwnd); break;
        case ID_MENU_CA_CERT:         HandleCACert(hwnd); break;
        case ID_MENU_SIGN_CERT:       HandleSignCert(hwnd); break;
        case ID_MENU_TLS_CERT:        HandleTlsCert(hwnd, TLS_TYPE_TLS); break;
        case ID_MENU_SERVER_CERT:     HandleTlsCert(hwnd, TLS_TYPE_SERVER); break;
        case ID_MENU_USER_CERT:       HandleTlsCert(hwnd, TLS_TYPE_USER); break;
        case ID_MENU_SELF_CERT:       HandleSelfCert(hwnd, TLS_TYPE_TLS); break;
        case ID_MENU_PKCS12:          HandleP12(hwnd); break;
        case ID_MENU_KEYGEN_RSA:      HandleKeyGenRSA(hwnd); break;
        case ID_MENU_KEYGEN_ECDSA:    HandleKeyGenECC(hwnd, BCRYPT_ECDSA_ALGORITHM, "ECDSA"); break;
        case ID_MENU_KEYGEN_ECDH:     HandleKeyGenECC(hwnd, BCRYPT_ECDH_ALGORITHM, "ECDH"); break;
        case ID_MENU_KEYGEN_DSA:      HandleKeyGenDSA(hwnd); break;
        case ID_MENU_KEYGEN_DH:       HandleKeyGenDH(hwnd); break;
        case ID_MENU_KEYGEN_AES:      HandleKeyGenAES(hwnd); break;
        case ID_MENU_KEYGEN_3DES:     HandleKeyGen3DES(hwnd); break;
        case ID_MENU_KEYGEN_CHACHA20: HandleKeyGenChaCha20(hwnd); break;
        case ID_MENU_KEYGEN_RANDOM:   HandleKeyGenRandom(hwnd); break;

        case ID_MENU_EXIT:  DestroyWindow(hwnd); break;
        case ID_MENU_ABOUT: ShowAbout(); break;
        }
        break;
    }
    case WM_CLOSE: DestroyWindow(hwnd); break;
    case WM_DESTROY:
        if (hFont) DeleteObject(hFont);
        if (hBoldFont) DeleteObject(hBoldFont);
        PostQuitMessage(0);
        break;
    default: return DefWindowProcW(hwnd, msg, wParam, lParam);
    }
    return 0;
}

// ===== WINMAIN =====
int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE, LPWSTR, int nCmdShow) {
    g_hInstance = hInstance;
    INITCOMMONCONTROLSEX icc = { sizeof(icc), ICC_STANDARD_CLASSES | ICC_WIN95_CLASSES };
    InitCommonControlsEx(&icc);

    const wchar_t CLASS_NAME[] = L"EncodingConverterClass";
    WNDCLASSEXW wc = {};
    wc.cbSize = sizeof(wc);
    wc.style = CS_HREDRAW | CS_VREDRAW;
    wc.lpfnWndProc = WndProc;
    wc.hInstance = hInstance;
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    wc.lpszClassName = CLASS_NAME;
    wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
    wc.hIconSm = LoadIcon(NULL, IDI_APPLICATION);
    if (!RegisterClassExW(&wc)) {
        MessageBoxW(NULL, L"RegisterClassExW failed", L"Error", MB_OK | MB_ICONERROR);
        return 1;
    }

    // Menus
    HMENU hMenuBar    = CreateMenu();
    HMENU hFileMenu   = CreatePopupMenu();
    HMENU hToolsMenu  = CreatePopupMenu();
    HMENU hKeyGenMenu = CreatePopupMenu();
    HMENU hKeyAsym    = CreatePopupMenu();
    HMENU hKeySym     = CreatePopupMenu();
    HMENU hKeyRandom  = CreatePopupMenu();
    HMENU hEditMenu   = CreatePopupMenu();
    HMENU hHelpMenu   = CreatePopupMenu();

    // File
    AppendMenuW(hFileMenu, MF_STRING, ID_MENU_FILE_OPEN, L"&Open File...\tCtrl+O");
    AppendMenuW(hFileMenu, MF_STRING, ID_MENU_FILE_SAVE, L"&Save Output...\tCtrl+S");
    AppendMenuW(hFileMenu, MF_SEPARATOR, 0, NULL);
    AppendMenuW(hFileMenu, MF_STRING, ID_MENU_EXIT, L"E&xit\tAlt+F4");
    AppendMenuW(hMenuBar, MF_POPUP, (UINT_PTR)hFileMenu, L"&File");

    // Tools
    AppendMenuW(hToolsMenu, MF_STRING, ID_MENU_ENCODING_DIALOG, L"Encoding / &Decoding...");
    AppendMenuW(hToolsMenu, MF_STRING, ID_MENU_CSR, L"Certificate &Signing Request...");
    AppendMenuW(hToolsMenu, MF_STRING, ID_MENU_CA_CERT, L"Create CA &Certificate...");
    AppendMenuW(hToolsMenu, MF_STRING, ID_MENU_SELF_CERT, L"Create &Self-Signed Certificate...");
    AppendMenuW(hToolsMenu, MF_STRING, ID_MENU_SIGN_CERT, L"Create CA-&Signed Certificate...");

    HMENU hCertMenu = CreatePopupMenu();
    AppendMenuW(hCertMenu, MF_STRING, ID_MENU_TLS_CERT,     L"&TLS Certificate (Server + SAN)...");
    AppendMenuW(hCertMenu, MF_STRING, ID_MENU_SERVER_CERT,   L"&Server Certificate...");
    AppendMenuW(hCertMenu, MF_STRING, ID_MENU_USER_CERT,     L"&User Certificate (Client)...");
    AppendMenuW(hToolsMenu, MF_POPUP, (UINT_PTR)hCertMenu, L"Create &Certificate (CA-Signed)...");

    AppendMenuW(hToolsMenu, MF_SEPARATOR, 0, NULL);
    AppendMenuW(hToolsMenu, MF_STRING, ID_MENU_PKCS7, L"Create PKCS#7 &Bundle...");
    AppendMenuW(hToolsMenu, MF_STRING, ID_MENU_PKCS12, L"PKCS#12 &Manager...");
    AppendMenuW(hToolsMenu, MF_SEPARATOR, 0, NULL);

    AppendMenuW(hKeyAsym, MF_STRING, ID_MENU_KEYGEN_RSA,   L"&RSA...");
    AppendMenuW(hKeyAsym, MF_STRING, ID_MENU_KEYGEN_ECDSA, L"&ECDSA...");
    AppendMenuW(hKeyAsym, MF_STRING, ID_MENU_KEYGEN_ECDH,  L"E&CDH...");
    AppendMenuW(hKeyAsym, MF_STRING, ID_MENU_KEYGEN_DSA,   L"&DSA...");
    AppendMenuW(hKeyAsym, MF_STRING, ID_MENU_KEYGEN_DH,    L"&DH...");
    AppendMenuW(hKeyGenMenu, MF_POPUP, (UINT_PTR)hKeyAsym, L"Asymmetric Key &Pairs");

    AppendMenuW(hKeySym, MF_STRING, ID_MENU_KEYGEN_AES,      L"&AES...");
    AppendMenuW(hKeySym, MF_STRING, ID_MENU_KEYGEN_3DES,     L"&3DES...");
    AppendMenuW(hKeySym, MF_STRING, ID_MENU_KEYGEN_CHACHA20, L"Cha&Cha20...");
    AppendMenuW(hKeyGenMenu, MF_POPUP, (UINT_PTR)hKeySym, L"Symmetric &Keys");

    AppendMenuW(hKeyRandom, MF_STRING, ID_MENU_KEYGEN_RANDOM, L"Random &Bytes...");
    AppendMenuW(hKeyGenMenu, MF_POPUP, (UINT_PTR)hKeyRandom, L"Random &Data");

    AppendMenuW(hToolsMenu, MF_POPUP, (UINT_PTR)hKeyGenMenu, L"Key &Generation");
    AppendMenuW(hMenuBar, MF_POPUP, (UINT_PTR)hToolsMenu, L"&Tools");

    // Edit
    AppendMenuW(hEditMenu, MF_STRING, ID_MENU_PASTE_INPUT, L"&Paste to Input\tCtrl+V");
    AppendMenuW(hEditMenu, MF_STRING, ID_MENU_COPY_OUTPUT, L"Copy &Output\tCtrl+C");
    AppendMenuW(hEditMenu, MF_SEPARATOR, 0, NULL);
    AppendMenuW(hEditMenu, MF_STRING, ID_MENU_CLEAR_BOTH, L"&Clear All");
    AppendMenuW(hMenuBar, MF_POPUP, (UINT_PTR)hEditMenu, L"&Edit");

    // Help
    AppendMenuW(hHelpMenu, MF_STRING, ID_MENU_ABOUT, L"&About");
    AppendMenuW(hMenuBar, MF_POPUP, (UINT_PTR)hHelpMenu, L"&Help");

    HWND hwnd = CreateWindowExW(0, CLASS_NAME, L"Encoding Converter & Key Generator",
        WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, 800, 520,
        NULL, hMenuBar, hInstance, NULL);
    if (!hwnd) {
        MessageBoxW(NULL, L"CreateWindowExW failed", L"Error", MB_OK | MB_ICONERROR);
        return 1;
    }

    ShowWindow(hwnd, nCmdShow);
    UpdateWindow(hwnd);

    MSG msg = {};
    while (GetMessageW(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessageW(&msg);
    }
    return 0;
}
