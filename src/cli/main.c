#include <stdio.h>
#include <stdlib.h>

int startDownload(const char *version);

int main(int argc, char *argv[]) {


  if (argc != 2) {
    fprintf(stderr, "Usage: %s <version>\n", argv[0]);
    exit(EXIT_FAILURE);
  }
  
  char *version = argv[1];

  int ret = startDownload(version);

  if (ret == 1) {
    perror("system");
    exit(EXIT_FAILURE);
  }

  return 0;
}

int startDownload(const char *version) {	
  char command[256];
  snprintf(command, sizeof(command), "softwareupdate --fetch-full-installer --full-installer-version %s", version);
  printf("%s\n", command);

  int ret = system(command);

  if (ret != 0) {
	  fprintf(stderr, "Command failed with error code: %d\n", ret);
  }

  return ret;
}
