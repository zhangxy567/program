#include <mysql.h>
#include <stdio.h>
#include <stdlib.h>

void finish_with_error(MYSQL *con) {
    fprintf(stderr, "%s\n", mysql_error(con));
    mysql_close(con);
    exit(1);
}

int main() {
    MYSQL *con = mysql_init(NULL);

    if (con == NULL) {
        fprintf(stderr, "mysql_init() failed\n");
        exit(1);
    }

    if (mysql_real_connect(con, "localhost", "root", "root", "aams", 3306, NULL, 0) == NULL) {
        finish_with_error(con);
    }

    if (mysql_query(con, "SELECT CURRENT_USER()")) {
        finish_with_error(con);
    }

    MYSQL_RES *result = mysql_store_result(con);
    if (result == NULL) {
        finish_with_error(con);
    }

    MYSQL_ROW row = mysql_fetch_row(result);
    if (row == NULL) {
        finish_with_error(con);
    }

    printf("Current user: %s\n", row[0]);

    mysql_free_result(result);

    if (mysql_query(con, "SELECT role FROM information_schema.APPLICABLE_ROLES WHERE user = CURRENT_USER()")) {
        finish_with_error(con);
    }

    result = mysql_store_result(con);
    if (result == NULL) {
        finish_with_error(con);
    }

    int num_fields = mysql_num_fields(result);
    MYSQL_ROW role_row;

    printf("Roles:\n");
    while ((role_row = mysql_fetch_row(result))) {
        for (int i = 0; i < num_fields; i++) {
            printf("%s ", role_row[i] ? role_row[i] : "NULL");
        }
        printf("\n");
    }

    mysql_free_result(result);
    mysql_close(con);

    return 0;
}
