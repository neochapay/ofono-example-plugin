Name: ofono-example-plugin
Version: 0.0.1
Release: 1
Summary: Ofono example plugin
Group: Development/Libraries
License: BSD
URL: https://github.com/neochapay/ofono-example-plugin
Source: %{name}-%{version}.tar.bz2

Requires: ofono
BuildRequires: ofono-devel

%description
Implements some examples for ofono plugin

%prep
%setup -q -n %{name}-%{version}

%build
./autogen.sh
%configure
make %{_smp_mflags}

%install
rm -rf %{buildroot}
%make_install
#libtool don't like lib without version
rm %{buildroot}/usr/lib/ofono/plugins/exampleplugin.so.0
rm %{buildroot}/usr/lib/ofono/plugins/exampleplugin.so
mv %{buildroot}/usr/lib/ofono/plugins/exampleplugin.so.0.0.0 %{buildroot}/usr/lib/ofono/plugins/exampleplugin.so

%files
%defattr(-,root,root,-)
%{_libdir}/ofono/plugins/exampleplugin.so