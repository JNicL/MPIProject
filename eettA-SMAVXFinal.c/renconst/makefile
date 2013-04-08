OBJS := \
  $(DIR)/CalcRenConst.o

$(LIB): $(LIB)($(OBJS))

$(LIB)($(OBJS)): Cdecl.d Cinline.d

LIBS += $(LIB)

VPATH := $(VPATH):$(DIR)

