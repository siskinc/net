//
// Created by siskinc on 18-4-3.
//

#ifndef NET_HTTPCODE_HPP
#define NET_HTTPCODE_HPP

namespace http {


// http://www.w3.org/Protocols/rfc2616/rfc2616-sec10.html
// https://tools.ietf.org/html/draft-ietf-webdav-protocol-10#section-10
//
enum HTTPCode
{
    CONTINUE = 100,
    SWITCHING_PROTOCOLS = 101,
    PROCESSING = 102,
    OK = 200,
    CREATED = 201,
    ACCEPTED = 202,
    NON_AUTHORITATIVE_INFORMATION = 203,
    NO_CONTENT = 204,
    RESET_CONTENT = 205,
    PARTIAL_CONTENT = 206,
    MULTI_STATUS = 207,
    ALREADY_REPORTED = 208,
    IM_USED = 226,
    MULTIPLE_CHOICES = 300,
    MOVED_PERMANENTLY = 301,
    FOUND = 302,
    SEE_OTHER = 303,
    NOT_MODIFIED = 304,
    USE_PROXY = 305,
    SWITCH_PROXY = 306,
    TEMPORARY_REDIRECT = 307,
    PERMANENT_REDIRECT = 308,
    BAD_REQUEST = 400,
    UNAUTHORIZED = 401,
    PAYMENT_REQUIRED = 402,
    FORBIDDEN = 403,
    NOT_FOUND = 404,
    METHOD_NOT_ALLOWED = 405,
    NOT_ACCEPTABLE = 406,
    PROXY_AUTHENTICATION_REQUIRED = 407,
    REQUEST_TIMEOUT = 408,
    CONFLICT = 409,
    GONE = 410,
    LENGTH_REQUIRED = 411,
    PRECONDITION_FAILED = 412,
    REQUEST_ENTITY_TOO_LARGE = 413,
    REQUEST_URI_TOO_LONG = 414,
    UNSUPPORTED_MEDIA_TYPE = 415,
    REQUESTED_RANGE_NOT_SATISFIABLE = 416,
    EXPECTATION_FAILED = 417,
    IM_A_TEAPOT = 418,
    ENHANCE_YOUR_CAIM = 420,
    MISDIRECTED_REQUEST = 421,
    UNPROCESSABLE_ENTITY = 422,
    LOCKED = 423,
    FAILED_DEPENDENCY = 424,
    UNORDERED_COLLECTION = 425,
    UPGRADE_REQUIRED = 426,
    PRECONDITION_REQUIRED = 428,
    TOO_MANY_REQUESTS = 429,
    REQUEST_HEADER_FIELDS_TOO_LARGE = 431,
    NO_RESPONSE = 444,
    BLOCKED_BY_WINDOWS_PARENTAL_CONTROLS = 450,
    UNAVAILABLE_FOR_LEGAL_REASONS = 451,
    REQUEST_HEADER_TOO_LARGE = 494,
    INTERNAL_SERVER_ERROR = 500,
    NOT_IMPLEMENTED = 501,
    BAD_GATEWAY = 502,
    SERVICE_UNAVAILABLE = 503,
    GATEWAY_TIMEOUT = 504,
    HTTP_VERSION_NOT_SUPPORTED = 505,
    VARIANT_ALSO_NEGOTIATES = 506,
    INSUFFICIENT_STORAGE = 507,
    LOOP_DETECTED = 508,
    NOT_EXTENDED = 510,
    NETWORK_AUTHENTICATION_REQUIRED = 511,
};

struct HTTPCodeDescription
{
    HTTPCode code;
    const std::string HTTP_code_description[2];
};

namespace {

const HTTPCodeDescription descriptions[] = {
        // https://www.rfc-editor.org/rfc/rfc7231.txt
        {CONTINUE,                        {"Continue",
                                                  "The initial part of a request has been received and has not yet been rejected by the server."}},
        {SWITCHING_PROTOCOLS,             {"Switching Protocols",
                                                  "The server understands and is willing to comply with the client's request, via the Upgrade header field, "
                                                  "for a change in the application protocol being used on this connection."}},
        {PROCESSING,                      {
                                           "Processing",
                                                  "the server is still processing the method."}},
        {MULTI_STATUS,                    {
                                           "Multi-Status",
                                                  "Servers MUST process PROPPATCH instructions in document order (an exception to the normal rule that ordering is irrelevant)."}},
        {OK,                              {"OK",
                                                  "The client's request was successfully received, understood, and accepted."}},
        {CREATED,                         {"Created",
                                                  "The request has been fulfilled and has resulted in one or more new resources being created."}},
        {ACCEPTED,                        {"Accepted",
                                                  "The request has been accepted for processing, but the processing has not been completed."}},
        {NON_AUTHORITATIVE_INFORMATION,   {"Non-Authoritative Information",
                                                  "The request was successful but the enclosed payload has been modified from that of the origin server's "
                                                  "200 (OK) response by a transforming proxy."}},
        {NO_CONTENT,                      {"No Content",
                                                  "The server has successfully fulfilled the request and there is no additional content to send "
                                                  "in the response payload body."}},
        {RESET_CONTENT,                   {"Reset Content",
                                                  "The server has fulfilled the request and desires that the user agent reset the \"document view\", "
                                                  "which caused the request to be sent, to its original state as received from the origin server."}},
        {PARTIAL_CONTENT,                 {"Partial Content",
                                                  "The server is successfully fulfilling a range request for the target resource by transferring "
                                                  "one or more parts of the selected representation that correspond to the satisfiable ranges found "
                                                  "in the request's Range header field."}},
        {MULTIPLE_CHOICES,                {"Multiple Choices",
                                                  "The target resource has more than one representation, each with its own more specific identifier, "
                                                  "and information about the alternatives is being provided so that the user (or user agent) "
                                                  "can select a preferred representation by redirecting its request to one or more of those identifiers."}},
        {MOVED_PERMANENTLY,               {"Moved Permanently",
                                                  "The target resource has been assigned a new permanent URI and any future references to this resource "
                                                  "ought to use one of the enclosed URIs."}},
        {FOUND,                           {"Found",
                                                  "The target resource resides temporarily under a different URI."}},
        {SEE_OTHER,                       {"See Other",
                                                  "The server is redirecting the user agent to a different resource, as indicated by a URI "
                                                  "in the Location header field, which is intended to provide an indirect response to the original request."}},
        {NOT_MODIFIED,                    {"Not Modified",
                                                  "A conditional GET or HEAD request has been received and would have resulted in a 200 (OK) response "
                                                  "if it were not for the fact that the condition evaluated to false."}},
        {USE_PROXY,                       {"Use Proxy",
                                                  "The requested resource MUST be accessed through the proxy given by the Location field."}},
        {TEMPORARY_REDIRECT,              {"Temporary Redirect",
                                                  "The target resource resides temporarily under a different URI and the user agent MUST NOT change "
                                                  "the request method if it performs an automatic redirection to that URI."}},
        {BAD_REQUEST,                     {"Bad Request",
                                                  "The server cannot or will not process the request due to something that is perceived to be a client error "
                                                  "(e.g., malformed request syntax, invalid request message framing, or deceptive request routing)."}},
        {UNAUTHORIZED,                    {"Unauthorized",
                                                  "The request has not been applied because it lacks valid authentication credentials for the target resource."}},
        {FORBIDDEN,                       {"Forbidden",
                                                  "The server understood the request but refuses to authorize it."}},
        {NOT_FOUND,                       {"Not Found",
                                                  "The origin server did not find a current representation for the target resource or is not willing "
                                                  "to disclose that one exists."}},
        {METHOD_NOT_ALLOWED,              {"Method Not Allowed",
                                                  "The method received in the request-line is known by the origin server but not supported by the target resource."}},
        {NOT_ACCEPTABLE,                  {"Not Acceptable",
                                                  "The target resource does not have a current representation that would be acceptable to the user agent, "
                                                  "according to the proactive negotiation header fields received in the request, and the server is unwilling "
                                                  "to supply a default representation."}},
        {PROXY_AUTHENTICATION_REQUIRED,   {"Proxy Authentication Required",
                                                  "The client needs to authenticate itself in order to use a proxy."}},
        {REQUEST_TIMEOUT,                 {"Request Timeout",
                                                  "The server did not receive a complete request message within the time that it was prepared to wait."}},
        {CONFLICT,                        {"Conflict",
                                                  "The request could not be completed due to a conflict with the current state of the target resource."}},
        {GONE,                            {"Gone",
                                                  "Access to the target resource is no longer available at the origin server and that this condition "
                                                  "is likely to be permanent."}},
        {LENGTH_REQUIRED,                 {"Length Required",
                                                  "The server refuses to accept the request without a defined Content-Length."}},
        {PRECONDITION_FAILED,             {"Precondition Failed",
                                                  "One or more conditions given in the request header fields evaluated to false when tested on the server."}},
        {REQUEST_ENTITY_TOO_LARGE,        {"Request Entity Too Large",
                                                  "The server is refusing to process a request because the request payload is larger than the server "
                                                  "is willing or able to process."}},
        {REQUEST_URI_TOO_LONG,            {"Request URI Too Long",
                                                  "The server is refusing to service the request because the request-target is longer than the server "
                                                  "is willing to interpret."}},
        {UNSUPPORTED_MEDIA_TYPE,          {"Unsupported Media Type",
                                                  "The origin server is refusing to service the request because the payload is in a format not supported "
                                                  "by this method on the target resource."}},
        {REQUESTED_RANGE_NOT_SATISFIABLE, {"Request Range Not Satisfiable",
                                                  "None of the ranges in the request's Range header field overlap the current extent of the selected resource "
                                                  "or the set of ranges requested has been rejected due to invalid ranges or an excessive request "
                                                  "of small or overlapping ranges."}},
        {EXPECTATION_FAILED,              {"Expectation Failed",
                                                  "The expectation given in the request's Expect header field could not be met by at least one of the inbound servers."}},
        {UPGRADE_REQUIRED,                {"Upgrade Required",
                                                  "The server refuses to perform the request using the current protocol but might be willing to do so "
                                                  "after the client upgrades to a different protocol."}},
        {INTERNAL_SERVER_ERROR,           {"Internal Server Error",
                                                  "The server encountered an unexpected condition that prevented it from fulfilling the request."}},
        {NOT_IMPLEMENTED,                 {"Not Implemented",
                                                  "The server does not support the functionality required to fulfill the request."}},
        {BAD_GATEWAY,                     {"Bad Gateway",
                                                  "The server, while acting as a gateway or proxy, received an invalid response from an inbound server it accessed "
                                                  "while attempting to fulfill the request."}},
        {SERVICE_UNAVAILABLE,             {"Service Unavailable",
                                                  "The server is currently unable to handle the request due to a temporary overload or scheduled maintenance, "
                                                  "which will likely be alleviated after some delay."}},
        {GATEWAY_TIMEOUT,                 {"Gateway Timeout",
                                                  "The server, while acting as a gateway or proxy, did not receive a timely response from an upstream server "
                                                  "it needed to access in order to complete the request."}},
        {HTTP_VERSION_NOT_SUPPORTED,      {"HTTP Version Not Supported",
                                                  "The server does not support, or refuses to support, the major version of  HTTP that was used in the request message."}},
};

inline const std::string &GetHTTPCodeDescription(HTTPCode code)
{
    return descriptions[code].HTTP_code_description[1];
}

}

}
#endif //NET_HTTPCODE_HPP
