/**
 * Copyright 2014, 2015, 2016 TAIN, Inc. all rights reserved.
 *
 * Licensed under the GNU GENERAL PUBLIC LICENSE, Version 3, 29 June 2007 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.gnu.org/licenses/
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 * -----------------------------------------------------------------
 * Copyright 2014, 2015, 2016 TAIN, Inc.
 *
 */
package tain.kr.com.proj.pos51.v02.common;

import org.apache.log4j.Logger;

/**
 * Code Templates > Comments > Types
 *
 * <PRE>
 *   -. FileName   : Version.java
 *   -. Package    : tain.kr.com.proj.pos51.v02.common
 *   -. Comment    :
 *   -. Author     : taincokr
 *   -. First Date : 2016. 3. 22. {time}
 * </PRE>
 *
 * @author taincokr
 *
 */
public class Version {

	private static boolean flag = true;

	private static final Logger log = Logger.getLogger(Version.class);

	///////////////////////////////////////////////////////////////////////////////////////////////
	
	/*
	 * 2016.03.22 : second version
	 */
	private static final String STR_VERSION = "TAIN_POS51 Version.2016.03.11_15.15.30";
	private static final String DESC_VERSION = "COMMENT : second version..";
	
	private Version() throws Exception {
		if (flag) {}
	}
	
	public String getString() throws Exception {
		return Version.STR_VERSION;
	}
	
	public String getDesc() throws Exception {
		return Version.DESC_VERSION;
	}
	
	public void print() throws Exception {
		System.out.println("STRING_VER > " + Version.STR_VERSION);
		System.out.println("DESCRIPTION> " + Version.DESC_VERSION);
	}
	
	///////////////////////////////////////////////////////////////////////////////////////////////
	
	private static Version instance = null;
	
	public static synchronized Version getInstance() throws Exception {
		
		if (instance == null) {
			instance = new Version();
		}
		
		return instance;
	}
	
	///////////////////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////////////////

	private static void test01(String[] args) throws Exception {
		
		if (flag) {
			
			Version.getInstance().print();
			
			log.debug(">>>>> " + Version.getInstance().getString());
			log.debug(">>>>> " + Version.getInstance().getDesc());
		}
	}
	
	public static void main(String[] args) throws Exception {
		
		if (flag) log.debug(">>>>> " + new Object(){}.getClass().getEnclosingClass().getName());
		
		if (flag) test01(args);
	}
}
