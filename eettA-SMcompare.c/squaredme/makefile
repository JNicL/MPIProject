NUMS :=

OBJS := $(NUMS) \
  $(DIR)/abbr0s.o \
  $(DIR)/abbr1s.o \
  $(DIR)/abbr0a.o \
  $(DIR)/abbr1a.o \
  $(DIR)/abbr0h.o \
  $(DIR)/abbr1h1.o \
  $(DIR)/abbr1h2.o \
  $(DIR)/abbr1h3.o \
  $(DIR)/abbr1h4.o \
  $(DIR)/abbr1h5.o \
  $(DIR)/abbr1h6.o \
  $(DIR)/abbr1h7.o \
  $(DIR)/abbr1h8.o \
  $(DIR)/abbr1h9.o \
  $(DIR)/abbr1h10.o \
  $(DIR)/abbr1h11.o \
  $(DIR)/abbr1h12.o \
  $(DIR)/abbr1h13.o \
  $(DIR)/abbr1h14.o \
  $(DIR)/abbr1h15.o \
  $(DIR)/abbr1h16.o \
  $(DIR)/abbr1h17.o \
  $(DIR)/abbr1h18.o \
  $(DIR)/born.o \
  $(DIR)/self.o \
  $(DIR)/self_Gen6.o \
  $(DIR)/vert.o \
  $(DIR)/vert_Gen6.o \
  $(DIR)/box.o \
  $(DIR)/SquaredME.o

$(LIB): $(LIB)($(OBJS))

$(LIB)($(OBJS)): $(DIR)/vars.h Cdecl.d Cinline.d

$(LIB)($(NUMS)): Cnum.d

LIBS += $(LIB)

