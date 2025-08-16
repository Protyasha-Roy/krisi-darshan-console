#include <stdio.h>
#include <string.h>
#include <curl/curl.h>
#include "menus.h"

#define MAX_CONTEXT_SIZE 5000
#define MAX_QUESTION_SIZE 512
#define MAX_PAYLOAD_SIZE (MAX_CONTEXT_SIZE + MAX_QUESTION_SIZE + 256)
#define MAX_RESPONSE_SIZE 5000

char response_buffer[MAX_RESPONSE_SIZE] = {0};
size_t response_size = 0;

size_t write_callback(void *contents, size_t size, size_t nmemb, void *userp) {
    size_t new_size = size * nmemb;
    if (response_size + new_size < MAX_RESPONSE_SIZE) {
        memcpy(response_buffer + response_size, contents, new_size);
        response_size += new_size;
        response_buffer[response_size] = '\0';
    }
    return new_size;
}

void bot(int id) {
    char context[MAX_CONTEXT_SIZE] = {0};

    FILE *context_file = fopen("Context.txt", "r");

    if (context_file == NULL) {
        printf("Error: Could not open context.txt\n");
        return;
    }

    int c;
    int i = 0;
    while ((c = fgetc(context_file)) != EOF && i < MAX_CONTEXT_SIZE - 1) {
        context[i] = c;
        i++;
    }
    context[i] = '\0';
    fclose(context_file);

    printf("Successfully read context.\n");

    char question[MAX_QUESTION_SIZE] = {0};

    do {
        getchar();
        printf("Enter your question about the app (or type 'E' to exit): ");
        if (fgets(question, MAX_QUESTION_SIZE, stdin) == NULL) {
            printf("Error reading input.\n");
            break;
        }

        size_t len = strlen(question);
        if (len > 0 && question[len - 1] == '\n') {
            question[len - 1] = '\0';
        }

        if (strcmp(question, "E") == 0) {
            break;
        }

        const char *json_prefix = "{\"contents\":[{\"parts\":[{\"text\":\"";
        const char *json_middle = "\"},{\"text\":\"";
        const char *json_suffix = "\"}]}]}";

        char payload[MAX_PAYLOAD_SIZE] = {0};

        strcpy(payload, json_prefix);
        strcat(payload, context);
        strcat(payload, json_middle);
        strcat(payload, question);
        strcat(payload, json_suffix);

        CURL *curl;
        CURLcode res;

        const char *api_key = "AIzaSyCwz73zo9XRYacf42p7Fqy7P24JLdADBKw";
        const char *url_prefix = "https://generativelanguage.googleapis.com/v1beta/models/gemini-1.5-flash:generateContent?key=";
        char full_url[256];
        snprintf(full_url, sizeof(full_url), "%s%s", url_prefix, api_key);

        curl_global_init(CURL_GLOBAL_DEFAULT);
        curl = curl_easy_init();

        if(curl) {
            curl_easy_setopt(curl, CURLOPT_URL, full_url);
            curl_easy_setopt(curl, CURLOPT_CAINFO, "certs/cacert.pem");
            curl_easy_setopt(curl, CURLOPT_POST, 1L);
            curl_easy_setopt(curl, CURLOPT_POSTFIELDS, payload);
            struct curl_slist *headers = NULL;
            headers = curl_slist_append(headers, "Content-Type: application/json");
            curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
            curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);
            curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response_buffer);

            res = curl_easy_perform(curl);

            if(res != CURLE_OK) {
                fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
            } else {
                const char *start_key = "\"text\": \"";
                char *start_ptr = strstr(response_buffer, start_key);

                if (start_ptr != NULL) {
                    start_ptr += strlen(start_key);
                    char *end_ptr = strstr(start_ptr, "\"");

                    if (end_ptr != NULL) {
                        *end_ptr = '\0';
                        printf("\nChatbot Response:\n");
                        printf("-------------------\n");
                        printf("%s\n", start_ptr);
                        printf("-------------------\n");
                    } else {
                        printf("Error: Could not find closing quote for 'text' field.\n");
                    }
                } else {
                    printf("Error: Could not find 'text' field in the JSON response.\n");
                }
            }

            curl_easy_cleanup(curl);
            curl_slist_free_all(headers);
        }
    } while (1);

    FarmerMenu(id);
    curl_global_cleanup();
}
