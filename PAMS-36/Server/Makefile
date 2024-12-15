BIN_DIR = bin
PROJ_DIR = proj

SUB_DIRS = $(PROJ_DIR)/rtspServer \
           $(PROJ_DIR)/plateSender \
           $(PROJ_DIR)/usrReceiver \
           $(PROJ_DIR)/rtspH264	\
		   $(PROJ_DIR)/tfliteRuntime

EXECUTABLES = $(BIN_DIR)/rtspServer \
              $(BIN_DIR)/plateSender \
              $(BIN_DIR)/usrReceiver \
              $(BIN_DIR)/rtspH264 \
			  $(BIN_DIR)/tfliteRuntime

# Default target: build all executables
all: $(EXECUTABLES)

# Rule to build each executable in its respective subdirectory
$(BIN_DIR)/%:
	$(MAKE) -C $(PROJ_DIR)/$* all
	@mkdir -p $(BIN_DIR)
	@mv $(PROJ_DIR)/$*/$* $(BIN_DIR)/$*

# Rule to clean all subdirectories and remove executables
clean:
	@for dir in $(SUB_DIRS); do \
		$(MAKE) -C $$dir clean; \
	done
	rm -f $(EXECUTABLES)

