// @@@ START COPYRIGHT @@@
//
// Licensed to the Apache Software Foundation (ASF) under one
// or more contributor license agreements.  See the NOTICE file
// distributed with this work for additional information
// regarding copyright ownership.  The ASF licenses this file
// to you under the Apache License, Version 2.0 (the
// "License"); you may not use this file except in compliance
// with the License.  You may obtain a copy of the License at
//
//   http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing,
// software distributed under the License is distributed on an
// "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
// KIND, either express or implied.  See the License for the
// specific language governing permissions and limitations
// under the License.
//
// @@@ END COPYRIGHT @@@

package org.trafodion.jdbc.t4;

import java.nio.charset.CharacterCodingException;
import java.nio.charset.UnsupportedCharsetException;

class SQLItemDescList_def {
	SQLItemDesc_def[] list;

	public SQLItemDescList_def(LogicalByteArray buf, boolean useOld, InterfaceConnection ic)
			throws CharacterCodingException, UnsupportedCharsetException {
		int length = buf.extractInt();

		if (length > 0) {
			if (!useOld) {
				length = buf.extractInt();
			}
			list = new SQLItemDesc_def[length];

			for (int i = 0; i < length; i++) {
				list[i] = (useOld) ? new SQLItemDescOld_def() : new SQLItemDesc_def();
				list[i].extractFromByteArray(buf, ic);
			}
		}
	}
}
