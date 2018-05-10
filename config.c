
#include <glib.h>
#include <stdio.h>
#include <string.h>
#include <glib.h>
#include "config.h"
#define DEBUG 1

int read_config()
{
  Settings *conf;
  GKeyFile *keyfile;
  GKeyFileFlags flags;
  GError *error = NULL;
  gsize length;

  /* Create a new GKeyFile object and a bitwise list of flags. */
  keyfile = g_key_file_new ();
  flags = G_KEY_FILE_KEEP_COMMENTS | G_KEY_FILE_KEEP_TRANSLATIONS;

  /* Load the GKeyFile from keyfile.conf or return. */
  if (!g_key_file_load_from_file (keyfile, "keyfile.conf", flags, &error))
  {
    g_error (error->message);
    return -1;
  }

  /* Create a new Settings object. If you are using GTK+ 2.8 or below, you should
   * use g_new() or g_malloc() instead! */
  conf = g_slice_new (Settings);

  /* Read in data from the key file from the group "username". */
  conf->name = g_key_file_get_string             (keyfile, "username",
                                                  "Name", NULL);
  conf->hello = g_key_file_get_locale_string     (keyfile, "username",
                                                  "Hi", "es", NULL);
  conf->boolean = g_key_file_get_boolean_list    (keyfile, "username",
                                                  "Bool", &length, NULL);
  conf->nums = g_key_file_get_integer_list       (keyfile, "username",
                                                  "Nums", &length, NULL);
  conf->strings = g_key_file_get_string_list     (keyfile, "username",
                                                  "Strings", &length, NULL);
  conf->meaning_of_life = g_key_file_get_integer (keyfile, "username",
                                                  "Int", NULL);
  conf->doubles = g_key_file_get_double_list     (keyfile, "username",
                                                 "Doubles", &length, NULL);
#if DEBUG
   printf("%s,%d\n",conf->name,conf->meaning_of_life);
#endif
   g_slice_free(Settings,conf);
   return 0;
}

int read_net_config()
{
  net_Settings *conf;
  GKeyFile *mixsysfile;
  GKeyFileFlags flags;
  GError *error = NULL;


  /* Create a new GKeyFile object and a bitwise list of flags. */
  mixsysfile = g_key_file_new ();
  flags = G_KEY_FILE_KEEP_COMMENTS | G_KEY_FILE_KEEP_TRANSLATIONS;

  /* Load the GKeyFile from keyfile.conf or return. */
  if (!g_key_file_load_from_file (mixsysfile, "mix_sys.conf", flags, &error))
  {
    g_error (error->message);
    return -1;
  }

  /* Create a new Settings object. If you are using GTK+ 2.8 or below, you should
   * use g_new() or g_malloc() instead! */
  conf = g_slice_new (net_Settings);

  /* Read in data from the key file from the group "username". */
  conf->local_ip_add = g_key_file_get_string             (mixsysfile, "network",
                                                  "local_ip_add", NULL);
  conf->gateway = g_key_file_get_string     (mixsysfile, "network",
                                                  "gateway",  NULL);
  conf->mask = g_key_file_get_string    (mixsysfile, "network",
                                                  "mask", NULL);
  conf->dns = g_key_file_get_string       (mixsysfile, "network",
                                                  "dns",  NULL);
  conf->server_ip_add = g_key_file_get_string     (mixsysfile, "modbus_server",
                                                  "server_ip_add", NULL);
  conf->server_ip_port = g_key_file_get_integer (mixsysfile, "modbus_server",
                                                  "server_ip_port", NULL);

#if DEBUG
   printf("%s,%d\n",conf->local_ip_add,conf->server_ip_port);
#endif
   g_slice_free(net_Settings,conf);
  return 0;
}

void write_net_config(void)
{
    GKeyFile *mixsysfile;
     GKeyFileFlags flags;
     GError *error = NULL;
     gsize length = 0;

      mixsysfile = g_key_file_new ();
  flags = G_KEY_FILE_KEEP_COMMENTS | G_KEY_FILE_KEEP_TRANSLATIONS;

  /* Load the GKeyFile from keyfile.conf or return. */
  if (!g_key_file_load_from_file (mixsysfile, "mix_sys.conf", flags, &error))
  {
    g_error (error->message);
    return -1;
  }
     g_key_file_set_string(mixsysfile,"network","local_ip_add","192.168.37.101");
     gchar* content=g_key_file_to_data(mixsysfile,&length,NULL);

 //   g_print("%s\n",content);

    FILE* fp = fopen("./mix_sys.conf","w");
    if(fp == NULL) return -1;
    fwrite(content,1,length,fp);
    fclose(fp);
    g_key_file_free (mixsysfile);

}
