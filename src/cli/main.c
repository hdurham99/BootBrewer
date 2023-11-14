#include <stdio.h>
#include <stdlib.h>

int start_download(const char *version);

typedef struct {
	char *version;
	char *name;
} VersionInfo;

VersionInfo versionTable[] = {
	{"14.1", "Sonoma"},
	{"13.6.1", "Ventura"},
	{"12.7.1", "Monterey"},
	{"11.7.10", "Big Sur"},
	{"10.15.7", "Catalina"},
	{"10.14.6", "Mojave"},
	{"10.13.6", "High Sierra"},
	{NULL, NULL}
};

int main(int argc, char *argv[]) {
  

  if (argc != 2) {
    fprintf(stderr, "Usage: %s <version>\n", argv[0]);
    exit(EXIT_FAILURE);
  }
  
  char *version = argv[1];

  int ret = start_download(version);

  if (ret == 1) {
    perror("system");
    exit(EXIT_FAILURE);
  }

  return 0;
}

int start_download(const char *version) {	
  char command[256];
  snprintf(command, sizeof(command), "softwareupdate --fetch-full-installer --full-installer-version %s", version);
  printf("%s\n", command);

  int ret = system(command);

  if (ret != 0) {
	  fprintf(stderr, "Command failed with error code: %d\n", ret);
  }

  return ret;
}
