#pragma once
//declaration of the enum for possible return values

enum returnValues {
	_success = 0,
	file_does_not_exist = -1,
	illegal_argument = -2,
	wrong_password = -3,
	create_fail = -4,
	add_fail = -5,
	delete_fail = -6,
	unsupported_extension = -7,
	already_exist = -8,
	null_file = -9,
	not_open = -10,
	is_open = -11
};