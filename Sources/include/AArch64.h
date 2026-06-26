#pragma once

#include <Universal.h>

#if __aarch64__
struct [[gnu::packed, gnu::aligned(8)]] CurrentEL {
	uint64_t : 2;
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
	uint64_t EL : 2;
	uint64_t : 4;
};

/// Hypervisor Configuration Register
///
/// Provides configuration controls for virtualization, including defining whether various operations are trapped to EL2.
struct [[gnu::packed, gnu::aligned(8)]] HCR {
	bool vm : 1;
	bool swio : 1;
	bool ptw : 1;
	bool fmo : 1;
	bool imo : 1;
	bool amo : 1;
	bool vf : 1;
	bool vi : 1;
	bool vse : 1;
	bool fb : 1;
	uint64_t bsu : 2;
	bool dc : 1;
	bool twi : 1;
	bool twe : 1;
	bool tid0 : 1;
	bool tid1 : 1;
	bool tid2 : 1;
	bool tid3 : 1;
	bool tsc : 1;
	bool tidcp : 1;
	bool tacr : 1;
	bool tsw : 1;
	bool tpcp : 1;
	bool tpu : 1;
	bool ttlb : 1;
	bool tvm : 1;
	bool tge : 1;
	bool tdz : 1;
	bool hcd : 1;
	bool trvm : 1;
	bool rw : 1;
	bool cd : 1;
	bool id : 1;
	bool e2h : 1;
	bool tlor : 1;
	bool terr : 1;
	bool tea : 1;
	bool miocnce : 1;
	bool res0_39 : 1;
	bool apk : 1;
	bool api : 1;
	bool nv : 1;
	bool nv1 : 1;
	bool at : 1;
	bool nv2 : 1;
	bool fwb : 1;
	bool fien : 1;
	bool res0_48 : 1;
	bool tid4 : 1;
	bool ticab : 1;
	bool amvoffen : 1;
	bool tocu : 1;
	bool enscxt : 1;
	bool ttlbis : 1;
	bool ttlbos : 1;
	bool ata : 1;
	bool dct : 1;
	bool tid5 : 1;
	bool tweden : 1;
	uint64_t twedel : 4;
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

/// Secure Configuration Register
///
/// Defines the configuration of the current Security state. It specifies:
/// - The Security state of EL0, EL1, and EL2. The Security state is Secure, Non-secure, or Realm.
/// - The Execution state at lower Exception levels.
/// - Whether IRQ, FIQ, SError exceptions, and External abort exceptions are taken to EL3.
/// - Whether various operations are trapped to EL3.
///
/// ### Configuration
/// This register is present only when EL3 is implemented and `FEAT_AA64` is implemented.
/// Otherwise, direct accesses to `SCR_EL3` are UNDEFINED.
///
/// ### Attributes
/// `SCR_EL3` is a 64-bit register.
struct SCR_EL3 {
	bool ns : 1;
	bool irq : 1;
	bool fiq : 1;
	bool ea : 1;
	uint64_t : 3;
	bool smd : 1;
	bool hce : 1;
	bool sif : 1;
	bool rw : 1;
	bool st : 1;
	bool twi : 1;
	bool twe : 1;
	bool tlor : 1;
	bool terr : 1;
	bool apk : 1;
	bool api : 1;
	bool eel2 : 1;
	bool ease : 1;
	bool nmea : 1;
	bool fien : 1;
	uint64_t : 3;
	bool enscxt : 1;
	bool ata : 1;
	bool fgten : 1;
	bool ecven : 1;
	bool tweden : 1;
	uint64_t twedel : 4;
	uint64_t : 1;
	bool amvoffen : 1;
	uint64_t : 28;
};

struct [[gnu::packed, gnu::aligned(8)]] SPSR {
	uint64_t m_4_0_ : 5;
	bool t : 1;
	bool f : 1;
	bool i : 1;
	bool a : 1;
	bool e : 1;
	uint64_t it_7_2_ : 6;
	uint64_t ge : 4;
	bool il : 1;
	bool dit : 1;
	bool pan : 1;
	bool ssbs : 1;
	bool j : 1;
	uint64_t it_1_0_ : 2;
	bool q : 1;
	bool v : 1;
	bool c : 1;
	bool z : 1;
	bool n : 1;
	bool : 1 ;
	bool ppend : 1;
	uint64_t : 2;
	bool uinj : 1;
};

void eret();
void brk0();

void zero_cntvoff_el2();
struct CurrentEL get_el();
struct HCR get_hcr_el2();
void set_hcr_el2(struct HCR);
void set_elr_el2(addr_t);
void set_elr_el3(addr_t);
struct MIPDR get_mpidr_el1();
void set_scr_el3(struct SCR_EL3);
void set_sp(uintptr_t);
void set_spsr_el2(struct SPSR);
void set_spsr_el3(struct SPSR);
#endif
