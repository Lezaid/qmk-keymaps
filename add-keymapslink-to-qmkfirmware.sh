#!/bin/bash

KEYBOARD="${1:-crkbd}"

echo "Keyboard name: $KEYBOARD"

##ln -sf ~/qmk-keymaps/crkbd/neodevdev ~/qmk_firmware/keyboards/crkbd/keymaps

keymaps_in_keyboard_dir=`ls -l ~/qmk-keymaps/crkbd | grep -oP '^d.* \K.*$'`
for keymap in $keymaps_in_keyboard_dir
do
  echo "Creating symlink: ~/qmk-keymaps/$KEYBOARD/$keymap --> ~/qmk_firmware/keyboards/$KEYBOARD/keymaps/$keymap"
  ln -sf ~/qmk-keymaps/$KEYBOARD/$keymap ~/qmk_firmware/keyboards/$KEYBOARD/keymaps
done
echo "Symlinks created!!!"

