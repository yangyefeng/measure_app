#ifndef CONFIG_H
#define CONFIG_H
typedef struct
{
  gchar *name, *hello;
  gboolean *boolean;
  int *nums;
  gchar **strings;
  int meaning_of_life;
  gdouble *doubles;
} Settings;
/**
网络服务器参数
*/
typedef struct
{
  gchar *local_ip_add;
  gchar *gateway;
  gchar *mask;
  gchar *dns;
  gchar *server_ip_add;
  int server_ip_port;
} net_Settings;


int read_config(void);
int read_net_config();
void write_net_config(void);
#endif
