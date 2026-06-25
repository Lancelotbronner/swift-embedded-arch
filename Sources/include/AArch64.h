#pragma once

#include <stdbool.h>
#include <stdint.h>

#if __aarch64__
void brk0();

struct CurrentEL get_el();
struct MIPDR get_mpidr_el1();

struct [[gnu::packed, gnu::aligned(8)]] CurrentEL {
	uint8_t : 2;
	/// Current Exception level.
 /// - `0b00` EL0.
 /// - `0b01` EL1.
 /// - `0b10` EL2.
 /// - `0b11` EL3.
 ///
 /// When the Effective value of `HCR_EL2.NV` is `1`, `EL1` read accesses to the `CurrentEL` register return the value of `0b10` in this field.
 ///
 /// The reset behavior of this field is:
 ///
 /// On a Warm reset:
 /// When the highest implemented Exception level is EL1, this field resets to '01'.
 /// When the highest implemented Exception level is EL2, this field resets to '10'.
 /// Otherwise, this field resets to '11'.
	uint8_t EL : 2;
	uint8_t : 4;
};

struct [[gnu::packed, gnu::aligned(8)]] MIPDR {
	/// Affinity level 0.
	/// The value of the `MPIDR.{Aff2, Aff1, Aff0}` or `MPIDR_EL1.{Aff3, Aff2, Aff1, Aff0}` set of fields of each PE must be unique within the system as a whole.
	uint8_t Aff0;
	/// Affinity level 1. See the description of `Aff0` for more information.
	uint8_t Aff1;
	/// Affinity level 2. See the description of `Aff0` for more information.
	uint8_t Aff2;
	/// Indicates whether the lowest level of affinity consists of logical PEs that are implemented using an interdependent approach, such as multithreading.
	///
	/// See the description of `aff0` for more information about affinity levels.
	///
	/// - `false`: Performance of PEs with different affinity level 0 values, and the same values for affinity level 1 and higher, is largely independent.
	/// - `true`: Performance of PEs with different affinity level 0 values, and the same values for affinity level 1 and higher, is very interdependent.
	///
	/// > Warning: This field does not indicate that multithreading is implemented and does not indicate that PEs with different affinity level 0 values, and the same values for affinity level 1 and higher are implemented.
	bool MT : 1;
	uint8_t : 5;
	/// Indicates a Uniprocessor system, as distinct from PE 0 in a multiprocessor system.
	///
	/// The value of this field is an IMPLEMENTATION DEFINED choice of:
	/// - `false`: Processor is part of a multiprocessor system.
	/// - `true`: Processor is part of a uniprocessor system.
	bool U : 1;
	bool : 1;
	uint8_t Aff3;
};
#endif
