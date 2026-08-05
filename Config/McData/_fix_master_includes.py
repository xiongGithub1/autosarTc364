from pathlib import Path

p = Path(__file__).with_name("Master.a2l")
text = p.read_text(encoding="utf-8", errors="replace")

old = r"""    /begin IF_DATA XCPplus 0x0104
      /include "Config\McData\XCP.a2l"  // TODO: Adapt path of A2L file accordingly
      /begin DAQ
        // TODO: Add or include further a2l file splitter that provide XCP Events
        /include "Config\McData\XCP_daq.a2l"          // TODO: Adapt path of A2L file accordingly. Remove if not required.
        /include "Config\McData\XCP_events.a2l"       // TODO: Adapt path of A2L file accordingly. Remove if not required.
        //include "Config\McData\Rte_XcpEvents.a2l"   // TODO: Adapt path of A2L file accordingly. Remove if not required.
        //include "Config\McData\McData_Events.a2l"   // TODO: Adapt path of A2L file accordingly. Remove if not required.
      /end DAQ
      /include "Config\McData\CanXCPAsr.a2l"    // TODO: Adapt path of A2L file accordingly. Remove if not required.
      /include "Config\McData\FrXCPAsr.a2l"     // TODO: Adapt path of A2L file accordingly. Remove if not required.
      /include "Config\McData\TcpIpXCPAsr.a2l"  // TODO: Adapt path of A2L file accordingly. Remove if not required.
    /end IF_DATA

    // TODO: Add or include further a2l splitter that provide measurement objects
    //include "Config\McData\Rte.a2l"     // TODO: Adapt path of A2L file accordingly. Remove if not required.
    //include "Config\McData\McData.a2l"  // TODO: Adapt path of A2L file accordingly. Remove if not required."""

new = r"""    /begin IF_DATA XCPplus 0x0104
      /* Master.a2l is in Config\McData — use same-folder includes */
      /include "Xcp.a2l"
      /begin DAQ
        /include "XCP_daq.a2l"
        /include "XCP_events.a2l"
        //include "McData_Events.a2l"
      /end DAQ
      /include "CanXcp_CT_CAN00_9df8a959_1073743619.a2l"
      /* Fr / Ethernet XCP not used in this project */
      //include "FrXCPAsr.a2l"
      //include "TcpIpXCPAsr.a2l"
    /end IF_DATA

    /* Appl calibration objects: import from ELF/MAP in CANape/ASAP2 Studio */
    //include "McData.a2l""""

if old not in text:
    raise SystemExit("OLD BLOCK NOT FOUND")

p.write_text(text.replace(old, new), encoding="utf-8")
print("updated", p)
